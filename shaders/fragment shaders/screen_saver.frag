// Author:
// Title:

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float plotR(vec2 st){
    if(abs((sin(-st.x+u_time/2.0)/2.0 + 0.2)/st.x - st.y) < 0.019){
    	return 1.0;   
    } else {
        return 0.0; 
    }
}
float plotG(vec2 st){
    if(abs((sin(st.x+u_time/3.0)/2.0 + 0.4)/st.x - st.y) < 0.015){
    	return 1.0;   
    } else {
        return 0.0; 
    }
}
float plotB(vec2 st){
    if(abs((sin(-st.x+u_time/2.0)/2.0 + 0.2)/st.x - st.y) < 0.018){
    	return 1.0;   
    } else {
        return 0.0; 
    }
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;

    vec3 color = vec3(plotR(vec2(st.x + 2.0, st.y - 0.3)),plotG(st),plotB(st));
    
    gl_FragColor = vec4(color,1.0);
}