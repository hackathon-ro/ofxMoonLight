attribute vec4 position;
attribute vec4 color;
attribute vec4 normal;
attribute vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

varying vec4 colorVarying;
varying vec2 texCoordVarying;

void main(){
	
	//get our current vertex position so we can modify it
	vec4 pos = projectionMatrix * modelViewMatrix * position;
	
    //finally set the pos to be that actual position rendered
	gl_Position = pos;
	
	colorVarying = color;
	texCoordVarying = texcoord;	
}
