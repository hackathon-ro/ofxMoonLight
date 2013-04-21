require 'PointObj'
class 'Branch'
 
function Branch:Branch(lev, n,points)
    self.level = lev
    self.num = n
    self.outerPoints = points
    self.midPoints = self:calcMidPoints()
    self.projPoints = self:calcStrutPoints()
 
    self.myBranches = {}

    if (self.level+1) < _maxLevels then
      local childBranch = Branch(self.level+1, 0, self.projPoints)
      table.insert(self.myBranches, childBranch)
      
    end

end
 
function  Branch:calcStrutPoints()
    local strutArray = {}
    for i = 1,table.getn(self.midPoints) do
      local nexti = i + 3
      if nexti > table.getn(self.midPoints) then
        nexti = nexti - table.getn(self.midPoints)
      end
      
      thisSP = self:calcProjPoint(self.midPoints[i], self.outerPoints[nexti])
      strutArray[i] = thisSP;
    end

    return strutArray;

end
 
function Branch:calcProjPoint(mp, op) 
    
    local px = 0
    local py = 0
    local adj = 0
    local opp = 0

    if op.x > mp.x then
      opp = op.x - mp.x
    else
      opp = mp.x - op.x
    end
    
    if op.y > mp.y then
      adj = op.y - mp.y
    else
      adj = mp.y - op.y;
    end
    
    if op.x > mp.x then
      px = mp.x + (opp * _strutFactor)
    else
      px = mp.x - (opp * _strutFactor)
    end
    
    if op.y > mp.y then
      py = mp.y + (adj * _strutFactor);
    else
      py = mp.y - (adj * _strutFactor);
    end
    
    return PointObj(px, py)
end
 
function Branch:calcMidPoints()
    
    local mpArray = {}

    --print("N=",table.getn(self.outerPoints))
    
    for i = 1,table.getn(self.outerPoints) do

      local nexti = i+1
      
      if nexti > table.getn(self.outerPoints) then
        --print("before nexti=",nexti)
        nexti = 1
        --print("after nexti=",nexti)
      end

    --print(self.outerPoints[i].x, self.outerPoints[nexti].x)

      local thisMP = self:calcMidPoint(self.outerPoints[i], self.outerPoints[nexti])
      mpArray[i] = thisMP;
    end
 
    return mpArray
end
 
function Branch:calcMidPoint(end1, end2)
    local mx = 0 
    local my = 0
    
    if end1.x > end2.x then
      mx = end2.x + ((end1.x - end2.x) /2)
    else
      mx = end1.x + ((end2.x - end1.x) /2);
    end
    
    if end1.y > end2.y then
      my = end2.y + ((end1.y - end2.y) /2);
    else
      my = end1.y + ((end2.y - end1.y) /2);
    end
    
    return PointObj(mx, my);
end

function Branch:drawMe()

    ofSetColor(red2, green2, blue2)
    ofSetLineWidth(5 - self.level)
    
    -- outer shape
    for i = 1,table.getn(self.outerPoints) do
      local nexti = i+1;
      
      if nexti > table.getn(self.outerPoints) then
        nexti = 1;
      end
      
      ofLine(self.outerPoints[i].x, self.outerPoints[i].y, self.outerPoints[nexti].x, self.outerPoints[nexti].y)
    end
    
    ofSetColor(red3, green3, blue3)
    ofSetLineWidth(0.5)

    ofFill(red3, green3, blue3)

    for j = 1, table.getn(self.midPoints) do
      ofEllipse(self.midPoints[j].x, self.midPoints[j].y, 15, 15)
    end
    

    ofSetColor(red4, green4, blue4)
    ofSetLineWidth(0.5)
    
    for j = 1, table.getn(self.midPoints) do
      ofFill(red5, green5, blue5)
      ofEllipse(self.midPoints[j].x, self.midPoints[j].y, 10, 10)
      ofLine(self.midPoints[j].x, self.midPoints[j].y, self.projPoints[j].x, self.projPoints[j].y)
      ofFill(red6, green6, blue6)
      ofEllipse(self.projPoints[j].x, self.projPoints[j].y, 10, 10)
    end
    
    for k = 1, table.getn(self.myBranches) do
      self.myBranches[k]:drawMe();
    end
end