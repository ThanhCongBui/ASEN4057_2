function [value, isterminal, direction] = ballEvents(t,y)

%%% Use height as the value of interest, check when it goes "below" zero
%%% and tell matlab that it needs to stop at that point.
value = y(2);
isterminal = 1;
direction = -1;


end
