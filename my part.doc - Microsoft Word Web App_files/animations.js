/* Copyright (C) 2012 Microsoft Corporation */(function(){var k=window,a=k.jQuery,e=k.wLive.Animations,i,d,s,h;if($B.RE_WebKit){i="-webkit-";d="webkit";h="webkitAnimationEnd"}else if($B.Firefox){i="-moz-";d="Moz";h="animationend"}else if($B.IE_M10){i="-ms-";d="ms";h="MSAnimationEnd"}else return;function o(h,d,f){for(var c=0,g=d.length;c<g;c++){var a=d[c];if(f===0)a.initialDelay=a.delay;if(typeof a.stagger==="function")a.delay=a.stagger(f,a.initialDelay);if(typeof a.offsetArray==="object"){var b=a.offsetArray.getOffset(c),e=a.getCss||q;if(a.endAtOffset)a.name=l(e,0,0,b.left,b.top);else a.name=l(e,b.left,b.top,0,0)}}}function r(a){a.style[d+"Animation"]=null}function g(b){b.each(function(){var b=a(this);b.css({height:b.height(),width:b.width()})})}function f(a){a.css({height:"",width:""})}function p(b,c,f){b.style[d+"AnimationDelay"]=c.map(function(a){return a.delay+"ms"}).join(",");b.style[d+"AnimationDuration"]=c.map(function(a){return a.duration+"ms"}).join(",");b.style[d+"AnimationTimingFunction"]=c.map(function(a){return a.timing}).join(",");b.style[d+"AnimationName"]=c.map(function(a){return a.name}).join(",");b.style[d+"AnimationFillMode"]=c.map(function(){return "both"}).join(",");var e=c.length,g=new a.Deferred(function(l){var d=function(){if(f)r(b);var c=a(b);clearTimeout(j);a(document).unbind(h,g);l.resolve()},g=function(a){if(a.target===b){e-=1;if(e===0)d()}};a(document).bind(h,g);var i=Math.max.apply(Math,c.map(function(a){return a.delay+a.duration})),j=k.setTimeout(d,i+100)});return g}function b(r,q,c){c=typeof c==="undefined"?true:c;var e,i=[],j=a.makeArray(q),m=a(r).filter(":visible"),k=a.makeArray(m),h=k.length,l=function(b,d){var a,e={left:0,top:0};o(b,j,d);a=p(b,j,c);i.push(a)},g=function(){e=a.Deferred().resolve()};try{if(h!==0){for(var b=0;b<h;b++){var d=k[b];if(d instanceof Array)for(var f=0,n=d.length;f<n;f++)l(d[f],b);else l(d,b)}e=a.when.apply(a,i)}else g()}catch(s){g()}return e}var j=i+"transform",c=function(c,e){var b,d;if(Array.isArray(c)&&c.length>0)b=c;else if(c&&c.hasOwnProperty("top")&&c.hasOwnProperty("left"))b=[c];else if(e)b=e;else b=[{top:"0px",left:"0px"}];d=b.length-1;if($B.rtl)a.each(b,function(b,a){a.left=-a.left});this.getOffset=function(a){if(a>d)a=d;return b[a]}},m=a("<style>");a("head").append(m);var n={};function q(a,b){if(a!==0||b!==0)return j+":translate("+a+"px,"+b+"px);";else return j+":none;"}function l(f,d,e,a,b){a=a||0;b=b||0;d=Math.floor(d);e=Math.floor(e);a=Math.floor(a);b=Math.floor(b);var g=m[0].sheet,c="translate_"+[d,e,a,b].join("_");if(!(c in n)){var h="@{0}keyframes {1} { from { {2} } to { {3} }}".format(i,c,f(d,e),f(a,b));try{g.insertRule(h,g.cssRules.length);n[c]=true}catch(j){}}return c}a.extend(e,{Direction:{Horizontal:"Width",Vertical:"Height"},Enabled:true,expand:function(h,i){var c=a(h);c.show();g(c);var d=b(h,[{name:"FadeIn",delay:200,duration:167,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"},{name:"Show"+(i||e.Direction.Vertical),delay:0,duration:367,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]);d.then(function(){f(c)});return d.promise()},collapse:function(h,i){var c=a(h);g(c);var d=b(h,[{name:"FadeOut",delay:0,duration:167,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"},{name:"Hide"+(i||e.Direction.Vertical),delay:167,duration:367,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]);d.then(function(){c.hide();f(c)});return d.promise()},fadeIn:function(c,d){a(c).show();return b(c,{name:"FadeIn",delay:0,duration:167,timing:"linear"},d).promise()},fadeOut:function(d,e){var c=b(d,{name:"FadeOut",delay:0,duration:167,timing:"linear"},e).promise();c.then(function(){a(d).hide()});return c},addToList:function(h,i){var c=a(h);c.show();g(c);var d=b(h,[{name:"ScaleIn",delay:167,duration:367,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"},{name:"FadeIn",delay:167,duration:167,timing:"linear"},{name:"Show"+(i||e.Direction.Vertical),delay:0,duration:500,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]);d.then(function(){f(c)});return d.promise()},deleteFromList:function(h,i){var c=a(h);c.show();g(c);var d=b(h,[{name:"ScaleOut",delay:0,duration:367,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"},{name:"FadeOut",delay:0,duration:167,timing:"linear"},{name:"Hide"+(i||e.Direction.Vertical),delay:167,duration:500,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]);d.then(function(){c.hide();f(c)});return d.promise()},addToSearchList:function(h,i){var c=a(h);c.show();g(c);var d=b(h,[{name:"FadeIn",delay:0,duration:50,timing:"linear"},{name:"Show"+(i||e.Direction.Vertical),delay:0,duration:300,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]);d.then(function(){f(c)});return d.promise()},deleteFromSearchList:function(h,i){var c=a(h);g(c);var d=b(h,[{name:"FadeOut",delay:0,duration:50,timing:"linear"},{name:"Hide"+(i||e.Direction.Vertical),delay:0,duration:300,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]);d.then(function(){c.hide();f(c)});return d.promise()},showEdgeUI:function(d,g,e){a(d).show();var f=new c(g);return b(d,{offsetArray:f,delay:0,duration:367,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"},e).promise()},showPanel:function(d,f){a(d).show();var e=new c(f);return b(d,{offsetArray:e,delay:0,duration:733,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}).promise()},hideEdgeUI:function(e,h,f){var g=new c(h),d=b(e,{offsetArray:g,delay:0,duration:367,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)",endAtOffset:true},f);d.then(function(){a(e).hide()});return d.promise()},hidePanel:function(e,g){var f=new c(g),d=b(e,{offsetArray:f,delay:0,duration:733,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)",endAtOffset:true});d.then(function(){a(e).hide()});return d.promise()},flyAway:function(e,f){var a=new c(f),d=b(e,[{name:"FlyAwayScale",delay:0,duration:366,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"},{offsetArray:a,delay:366,duration:366,timing:"cubic-bezier(0.11, 0.5, 0.24, 0.96)",endAtOffset:true,getCss:function(b,c){var a="";if(b!==0||c!==0)a="left:"+b+"px; top:"+c+"px";return a}},{name:"FadeOut",delay:366,duration:366,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]);return d.promise()},showPopup:function(d,f){a(d).show();var e=new c(f,[{top:"50px",left:"0px"}]);return b(d,[{name:"FadeIn",delay:83,duration:83,timing:"linear"},{offsetArray:e,delay:0,duration:367,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}]).promise()},hidePopup:function(c){return b(c,{name:"FadeOut",delay:0,duration:83,timing:"linear"}).promise().then(function(){a(c).hide()})}});if($B.IE_M10)a.extend(e,{enterContent:function(d,f,e){a(d).show();return b(d,[{offsetArray:new c(f,[{top:"0px",left:"40px"}]),delay:0,duration:370,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"},{name:"FadeIn",delay:0,duration:170,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}],e).promise()},exitContent:function(e,g,f){var d=b(e,[{offsetArray:new c(g,[{top:"0px",left:"-10px"}]),delay:0,duration:80,timing:"linear"},{name:"FadeOut",delay:0,duration:80,timing:"linear"}],f);d.then(function(){a(e).hide()});return d.promise()},reveal:function(m,k,l,f,g){var h=new c(l,[{top:"0px",left:"-10px"}]),i=b(k,{offsetArray:h,delay:0,duration:450,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}),d=b(f,{name:"FadeIn",delay:0,duration:50,timing:"linear"});d.then(function(){a(f).css("opacity",1)});var e=b(g,{name:"Tap",delay:0,duration:200,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"});e.then(function(){a(g).css(j,"scale(1.05)")});return a.when(i,d,e).promise()},hide:function(m,k,l,f,g){var h=new c(l,[{top:"0px",left:"10px"}]),i=b(k,{offsetArray:h,delay:0,duration:200,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"}),d=b(f,{name:"FadeOut",delay:0,duration:50,timing:"linear"});d.then(function(){a(f).css("opacity",0)});var e=b(g,{name:"Untap",delay:0,duration:100,timing:"cubic-bezier(0.1, 0.9, 0.2, 1)"});e.then(function(){a(g).css(j,"none")});return a.when(i,d,e).promise()}})})()