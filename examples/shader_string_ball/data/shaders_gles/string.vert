attribute vec4 position;
attribute vec4 color;
attribute vec4 normal;
attribute vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 trans;

varying vec4 colorVarying;
varying vec2 texCoordVarying;

uniform float timeValX;
uniform float timeValY;
uniform vec2 mouse;

//generate a random value from four points
vec4 rand(vec2 A,vec2 B,vec2 C,vec2 D){ 

	vec2 s=vec2(12.9898,78.233); 
	vec4 tmp=vec4(dot(A,s),dot(B,s),dot(C,s),dot(D,s)); 

	return fract(sin(tmp) * 43758.5453)* 2.0 - 1.0; 
} 

//this is similar to a perlin noise function
float noise(vec2 coord,float d){ 

	vec2 C[4]; 

	float d1 = 1.0/d;

	C[0]=floor(coord*d)*d1; 

	C[1]=C[0]+vec2(d1,0.0); 

	C[2]=C[0]+vec2(d1,d1); 

	C[3]=C[0]+vec2(0.0,d1);


	vec2 p=fract(coord*d); 

	vec2 q=1.0-p; 

	vec4 w=vec4(q.x*q.y,p.x*q.y,p.x*p.y,q.x*p.y); 

	return dot(vec4(rand(C[0],C[1],C[2],C[3])),w); 
} 


void main(){
    
	//get our current vertex position so we can modify it
    vec4 initPos = position;
	vec4 posProj = projectionMatrix * modelViewMatrix * trans * position;
	
	//generate some noise values based on vertex position and the time value which comes in from our OF app
	float noiseAmntX = noise( vec2(-timeValX + posProj.x / 1000.0, 100.0), 20.0 );
	float noiseAmntY = noise( vec2(timeValY + posProj.y / 1000.0, posProj.x / 2000.0), 20.0 );


	vec3 d = vec3(initPos.x, initPos.y, initPos.z) - vec3(0.0, 0.0, 0.0);
	float len =  sqrt(d.x*d.x + d.y*d.y + d.z*d.z);
	if(len > 105.0){
		//lets get the distance into 0-1 ranges
		float pct = len / 105.0; 
		
		//this turns our linear 0-1 value into a curved 0-1 value
		pct *= pct;

		//flip it so the closer we are the greater the repulsion
		pct = 1.0 - pct;
		
		//normalize our repulsion vector
		d /= len;
		
		//apply the repulsion to our position
        initPos.x += noiseAmntX * pct * 12.0;
        initPos.y += noiseAmntY * pct * 8.0;
	}

	posProj = projectionMatrix * modelViewMatrix * trans * initPos;

	//lets also figure out the distance between the mouse and the vertex and apply a repelling force away from the mouse
	vec2 md = vec2(posProj.x, posProj.y) - mouse;
	len =  sqrt(md.x*md.x + md.y*md.y);
	if(len < 100.0 && len > 0.0) {
		
		//lets get the distance into 0-1 ranges
		float pct = len / 100.0; 
		
		//this turns our linear 0-1 value into a curved 0-1 value
		pct *= pct;

        pct = 1.0 - pct;

		//flip it so the closer we are the greater the repulsion
		
		//normalize our repulsion vector
		md /= len;
		
		//apply the repulsion to our position
		posProj.x += md.x * pct * 15.0;
		posProj.y += md.y * pct * 15.0;
	}




	
	//finally set the pos to be that actual position rendered
	gl_Position = posProj;

	colorVarying = color;
	texCoordVarying = texcoord;
}
