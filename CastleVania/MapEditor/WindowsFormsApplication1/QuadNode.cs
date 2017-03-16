using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Drawing;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class QuadNode
    {

        string id;
        QuadNode LeftTop, RightTop, LeftBot, RightBot;
        Rectangle rec;
        public List<ObjectGame> listObj;

        public QuadNode(string _id, Rectangle _rec)
        {
            id = _id;
            rec = _rec;
            LeftBot = null;
            LeftTop = null;
            RightBot = null;
            RightTop = null;
            listObj = new List<ObjectGame>();
        }

        public void CreateSubNode()
        {

            int halfWidth = rec.Width / 2;
            int halfHeight = rec.Height / 2;
            if (halfWidth < 136 || listObj.Count == 0)
            {
                LeftBot = null;
                LeftTop = null;
                RightBot = null;
                RightTop = null;
                return;
            }
            LeftTop = new QuadNode(this.id + "0", new Rectangle(rec.Location, new Size(halfWidth, halfHeight)));
            RightTop = new QuadNode(this.id + "1", new Rectangle(new Point(rec.Left + halfWidth, rec.Top), new Size(halfWidth, halfHeight)));
            LeftBot = new QuadNode(this.id + "2", new Rectangle(new Point(rec.Left, rec.Top + halfHeight), new Size(halfWidth, halfHeight)));
            RightBot = new QuadNode(this.id + "3", new Rectangle(new Point(rec.Left + halfWidth, rec.Top + halfHeight), new Size(halfWidth, halfHeight)));
        }

        public void BuildTree()
        {
            CreateSubNode();
            if (LeftTop == null)
                return;
            foreach (ObjectGame o in listObj)
            {
                Rectangle r = new Rectangle(o.location.X, o.location.Y, o.bm.Width, o.bm.Height);
                if (LeftTop.rec.IntersectsWith(r))
                {
                    LeftTop.listObj.Add(o);
                }
                if (RightTop.rec.IntersectsWith(r))
                {
                    RightTop.listObj.Add(o);
                }
                if (LeftBot.rec.IntersectsWith(r))
                {
                    LeftBot.listObj.Add(o);
                }
                if (RightBot.rec.IntersectsWith(r))
                {
                    RightBot.listObj.Add(o);
                }
            }

            LeftTop.BuildTree();
            RightTop.BuildTree();
            LeftBot.BuildTree();
            RightBot.BuildTree();
            listObj.Clear();

        }

        public void Insert(ObjectGame obj)
        {
            Rectangle r = new Rectangle(obj.location.X, obj.location.Y, obj.bm.Width, obj.bm.Height);

            if (LeftBot == null)
                CreateSubNode();

            if (LeftTop != null && LeftTop.rec.Contains(r))
            {
                LeftTop.Insert(obj);
                return;
            }
            if (RightTop != null && RightTop.rec.Contains(r))
            {
                RightTop.Insert(obj);
                return;
            }
            if (LeftBot != null && LeftBot.rec.Contains(r))
            {
                LeftBot.Insert(obj);
                return;
            }
            if (RightBot != null && RightBot.rec.Contains(r))
            {
                RightBot.Insert(obj);
                return;
            }

            this.listObj.Add(obj);
        }

        public void Save(StreamWriter sw)
        {
            int subnode = 0;
            if (LeftTop != null)
                subnode = 4;

            sw.Write(rec.X.ToString() + "\t\t\t" + rec.Y.ToString() + "\t\t\t" + rec.Width.ToString() + "\t\t\t" + rec.Height.ToString() + "\t\t\t" + subnode + "\t\t\t" + listObj.Count + "\t\t\t");
            if (listObj.Count > 0)
            {
                foreach (ObjectGame o in listObj)
                    sw.Write(o.index + "\t\t");
            }
            sw.WriteLine();
            if (LeftTop != null)
            {
                LeftTop.Save(sw);
                RightTop.Save(sw);
                LeftBot.Save(sw);
                RightBot.Save(sw);
            }
        }

        public void Clear()
        {
            LeftBot = null;
            LeftTop = null;
            RightBot = null;
            RightTop = null;
            listObj = new List<ObjectGame>();
        }
    }
}