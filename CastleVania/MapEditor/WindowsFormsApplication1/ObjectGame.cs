using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace WindowsFormsApplication1
{
    public enum ObjectType
    {
        Enemy,
        Thing
    }
    public class ObjectGame
    {
        public Bitmap bm;
        public int ID;
        public int indexanotherobj;
        public int index;
        public Point location;
        public List<String> listIDInTree;
        public ObjectType objectType;
        public Rectangle moveSpace;
        public ObjectGame()
        { }
        public ObjectGame(Bitmap b, int id, String type)
        {
            bm = new Bitmap(b);
            ID = id;
            if (type == "Enemy")
            {
                objectType = ObjectType.Enemy;
            }
            else
            {
                objectType = ObjectType.Thing;
            }
            moveSpace = new Rectangle();
            indexanotherobj = -1;

        }

        public void SetLocation(int x, int y)
        {
            location = new Point(x, y);
        }

        public Point GetLocation()
        {
            return new Point(location.X, location.Y);
        }

        //public Point GetLocation()
        //{
        //    return location;
        //}
    }
}
