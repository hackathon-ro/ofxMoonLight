#ifdef GL_ES
// define default precision for float, vec, mat.
precision highp float;
#endif

uniform sampler2D src_tex_unit0;
uniform float useTexture;
uniform float useColors;
uniform vec4 color;

varying float depth;
varying vec4 colorVarying;
varying vec2 texCoordVarying;

void main(){
    gl_FragColor = color * 0.7;    
}
