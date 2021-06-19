// Author: Kalsifer
// Title: Italian flag

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
	
    vec3 color = vec3(0.0,1.0,0.0);
    color = mix(color, vec3(1.0,1.0,1.0), vec3(step(0.333,st.x)));
    color = mix(color, vec3(1.0,0.0,0.0), vec3(step(0.666,st.x)));

    gl_FragColor = vec4(color,1.0);
}