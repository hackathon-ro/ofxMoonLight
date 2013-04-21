class 'PointObj'
 
function PointObj:PointObj(ex,  why)

    self.x = ex
    self.y = why
 
    rad = 15
    ofFill(red1, green1, blue1); 
    
    if (ex > (width - rad)) or (why < rad) then
      xdirection  = xdirection*(-1)
    end

    if (why > (height - rad)) or (why < rad) then
      ydirection = ydirection * (-1)
    end
    
    ofEllipse(ex + (xdirection*xspeed), why + (ydirection*yspeed), rad, rad);
end