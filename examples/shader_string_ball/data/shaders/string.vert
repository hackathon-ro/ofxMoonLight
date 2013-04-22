#version 120

uniform mat4 trans;
uniform vec2 mouse;

uniform float timeValX = 1.0;
uniform float timeValY = 1.0;

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

	gl_TexCoord[0] = gl_MultiTexCoord0;
	
	//get our current vertex position so we can modify it
    vec4 initPos = gl_Vertex;
	vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * trans * gl_Vertex;
	vec4 center = gl_ProjectionMatrix * gl_ModelViewMatrix * trans * vec4(0.0, 0.0, 0.0, 1.0);

	//generate some noise values based on vertex position and the time value which comes in from our OF app
    float noiseAmntX = noise( vec2(-timeValX + pos.x / 1000.0f, 100.0f), 20.0 );
    float noiseAmntY = noise( vec2(timeValY + pos.y / 1000.0f, pos.x / 2000.0f), 20.0 );

	vec3 d = vec3(initPos.x, initPos.y, initPos.z) - vec3(0.0, 0.0, 0.0);
	float len =  sqrt(d.x*d.x + d.y*d.y + d.z*d.z);
	if(len > 220 && len < 255){
		//lets get the distance into 0-1 ranges
		float pct = len / 255.0; 
		
		//this turns our linear 0-1 value into a curved 0-1 value
		pct *= pct;

		//flip it so the closer we are the greater the repulsion
		pct = 1.0 - pct;
		
		//normalize our repulsion vector
		d /= len;
		
		//apply the repulsion to our position
        initPos.x += noiseAmntX * pct * 15;
        initPos.y += noiseAmntY * pct * 10;
	}

	vec4 posProj = gl_ProjectionMatrix * gl_ModelViewMatrix * trans * initPos;

////lets also figure out the distance between the mouse and the vertex and apply a repelling force away from the mouse
//vec2 md = vec2(posProj.x, posProj.y) - mouse;
//len =  sqrt(md.x*md.x + md.y*md.y);
//if(len < 100.0 && len > 0.0) {
//	
//	//lets get the distance into 0-1 ranges
//	float pct = len / 100.0; 
//	
//	//this turns our linear 0-1 value into a curved 0-1 value
//	pct *= pct;
//
//    pct = 1 - pct;
//
//	//flip it so the closer we are the greater the repulsion
//	
//	//normalize our repulsion vector
//	md /= len;
//	
//	//apply the repulsion to our position
//	posProj.x += md.x * pct * 25.0;
//	posProj.y += md.y * pct * 25.0;
//}


	//modify our position with the smooth noise
	gl_Position = posProj;
	//finally set the pos to be that actual position rendered

	//modify our color
	gl_FrontColor = gl_Color;
}
