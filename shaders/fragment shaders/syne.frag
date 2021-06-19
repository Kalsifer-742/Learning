// Author:
// Title:

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float plot(vec2 st){
    return abs((sin((st.x+u_time/5.0)*3.14*2.0)/2.0) + 0.5 - st.y) < 0.01 ? 1.0 : 0.0;
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;

    vec3 color = vec3(0.0,plot(st),0.0);
    
    gl_FragColor = vec4(color,1.0);
}