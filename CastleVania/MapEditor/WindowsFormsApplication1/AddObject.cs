using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class AddObject : Form
    {

        public AddObject()
        {

            InitializeComponent();


        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            foreach (ObjectGame o in Form1.listobj)
                if (o.ID == int.Parse(comboBox1.Text))
                    pictureBox1.BackgroundImage = o.bm;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }



    }
}
