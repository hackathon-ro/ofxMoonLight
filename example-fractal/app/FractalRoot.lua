require 'Branch'
require 'PointObj'
class 'FractalRoot'
 
function FractalRoot:FractalRoot(startAngle)
    
    self.pointArr = {}

    self.centX = width/2
    self.centY = height/2
    self.angleStep = 360.00/_numSides

    for i = 0,360,self.angleStep do
      local x = self.centX + (Rad*math.cos(180*(startAngle + i)/math.pi))
      local y = self.centY + (Rad*math.sin(180*(startAngle + i)/math.pi))
      table.insert(self.pointArr,PointObj(x, y))
    end
    
    self.rootBranch = Branch(0, 0, self.pointArr)
    
end
 
function FractalRoot:drawShape()
    self.rootBranch:drawMe()
end