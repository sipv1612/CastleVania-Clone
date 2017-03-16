namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.flpTile = new System.Windows.Forms.FlowLayoutPanel();
            this.openFolder = new System.Windows.Forms.FolderBrowserDialog();
            this.saveFile = new System.Windows.Forms.SaveFileDialog();
            this.flpOthers = new System.Windows.Forms.FlowLayoutPanel();
            this.lblNewMapWidth = new System.Windows.Forms.Label();
            this.lblNewMapHeight = new System.Windows.Forms.Label();
            this.txtWidth = new System.Windows.Forms.TextBox();
            this.txtHeight = new System.Windows.Forms.TextBox();
            this.lblNewMapUnit1 = new System.Windows.Forms.Label();
            this.lblNewMapUnit2 = new System.Windows.Forms.Label();
            this.btnSaveMatrix = new System.Windows.Forms.Button();
            this.btnSaveMap = new System.Windows.Forms.Button();
            this.btnSaveTile = new System.Windows.Forms.Button();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.flowLayoutPanel2 = new System.Windows.Forms.FlowLayoutPanel();
            this.pbMap = new System.Windows.Forms.PictureBox();
            this.pbOthers = new System.Windows.Forms.PictureBox();
            this.pbTile = new System.Windows.Forms.PictureBox();
            this.btnAddOtherObj = new System.Windows.Forms.Button();
            this.btnAddObj = new System.Windows.Forms.Button();
            this.btnNew = new System.Windows.Forms.Button();
            this.btnLoad = new System.Windows.Forms.Button();
            this.flpTile.SuspendLayout();
            this.flpOthers.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.flowLayoutPanel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbMap)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbOthers)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbTile)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // flpTile
            // 
            this.flpTile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.flpTile.AutoScroll = true;
            this.flpTile.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.flpTile.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.flpTile.Controls.Add(this.pbTile);
            this.flpTile.Location = new System.Drawing.Point(4, 434);
            this.flpTile.Margin = new System.Windows.Forms.Padding(4);
            this.flpTile.Name = "flpTile";
            this.flpTile.Size = new System.Drawing.Size(480, 59);
            this.flpTile.TabIndex = 3;
            // 
            // flpOthers
            // 
            this.flpOthers.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.flpOthers.AutoScroll = true;
            this.flpOthers.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.flpOthers.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.flpOthers.Controls.Add(this.pbOthers);
            this.flpOthers.Location = new System.Drawing.Point(492, 434);
            this.flpOthers.Margin = new System.Windows.Forms.Padding(4);
            this.flpOthers.Name = "flpOthers";
            this.flpOthers.Size = new System.Drawing.Size(478, 59);
            this.flpOthers.TabIndex = 9;
            // 
            // lblNewMapWidth
            // 
            this.lblNewMapWidth.AutoSize = true;
            this.lblNewMapWidth.Location = new System.Drawing.Point(320, 9);
            this.lblNewMapWidth.Name = "lblNewMapWidth";
            this.lblNewMapWidth.Size = new System.Drawing.Size(48, 17);
            this.lblNewMapWidth.TabIndex = 11;
            this.lblNewMapWidth.Text = "Width:";
            // 
            // lblNewMapHeight
            // 
            this.lblNewMapHeight.AutoSize = true;
            this.lblNewMapHeight.Location = new System.Drawing.Point(320, 34);
            this.lblNewMapHeight.Name = "lblNewMapHeight";
            this.lblNewMapHeight.Size = new System.Drawing.Size(53, 17);
            this.lblNewMapHeight.TabIndex = 12;
            this.lblNewMapHeight.Text = "Height:";
            // 
            // txtWidth
            // 
            this.txtWidth.Location = new System.Drawing.Point(374, 6);
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(61, 22);
            this.txtWidth.TabIndex = 13;
            this.txtWidth.TextChanged += new System.EventHandler(this.txtWidth_TextChanged);
            this.txtWidth.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtWidth_KeyPress);
            // 
            // txtHeight
            // 
            this.txtHeight.Location = new System.Drawing.Point(374, 31);
            this.txtHeight.Name = "txtHeight";
            this.txtHeight.Size = new System.Drawing.Size(61, 22);
            this.txtHeight.TabIndex = 14;
            this.txtHeight.TextChanged += new System.EventHandler(this.txtHeight_TextChanged);
            this.txtHeight.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtHeight_KeyPress);
            // 
            // lblNewMapUnit1
            // 
            this.lblNewMapUnit1.AutoSize = true;
            this.lblNewMapUnit1.Location = new System.Drawing.Point(441, 9);
            this.lblNewMapUnit1.Name = "lblNewMapUnit1";
            this.lblNewMapUnit1.Size = new System.Drawing.Size(31, 17);
            this.lblNewMapUnit1.TabIndex = 15;
            this.lblNewMapUnit1.Text = "Tile";
            // 
            // lblNewMapUnit2
            // 
            this.lblNewMapUnit2.AutoSize = true;
            this.lblNewMapUnit2.Location = new System.Drawing.Point(441, 34);
            this.lblNewMapUnit2.Name = "lblNewMapUnit2";
            this.lblNewMapUnit2.Size = new System.Drawing.Size(31, 17);
            this.lblNewMapUnit2.TabIndex = 16;
            this.lblNewMapUnit2.Text = "Tile";
            // 
            // btnSaveMatrix
            // 
            this.btnSaveMatrix.Location = new System.Drawing.Point(680, 18);
            this.btnSaveMatrix.Name = "btnSaveMatrix";
            this.btnSaveMatrix.Size = new System.Drawing.Size(94, 23);
            this.btnSaveMatrix.TabIndex = 17;
            this.btnSaveMatrix.Text = "Save Matrix";
            this.btnSaveMatrix.UseVisualStyleBackColor = true;
            this.btnSaveMatrix.Click += new System.EventHandler(this.btnSaveMatrix_Click);
            // 
            // btnSaveMap
            // 
            this.btnSaveMap.Location = new System.Drawing.Point(580, 18);
            this.btnSaveMap.Name = "btnSaveMap";
            this.btnSaveMap.Size = new System.Drawing.Size(94, 23);
            this.btnSaveMap.TabIndex = 18;
            this.btnSaveMap.Text = "Save Map";
            this.btnSaveMap.UseVisualStyleBackColor = true;
            this.btnSaveMap.Click += new System.EventHandler(this.btnSaveMap_Click);
            // 
            // btnSaveTile
            // 
            this.btnSaveTile.Location = new System.Drawing.Point(480, 18);
            this.btnSaveTile.Name = "btnSaveTile";
            this.btnSaveTile.Size = new System.Drawing.Size(94, 23);
            this.btnSaveTile.TabIndex = 19;
            this.btnSaveTile.Text = "Save Tile";
            this.btnSaveTile.UseVisualStyleBackColor = true;
            this.btnSaveTile.Click += new System.EventHandler(this.btnSaveTile_Click);
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel2.AutoSize = true;
            this.tableLayoutPanel2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50.10331F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 49.89669F));
            this.tableLayoutPanel2.Controls.Add(this.flowLayoutPanel2, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.flpOthers, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.flpTile, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.btnAddOtherObj, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.btnAddObj, 0, 2);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(0, 60);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 3;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 78.69368F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 12.45328F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 8.85304F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(974, 547);
            this.tableLayoutPanel2.TabIndex = 10;
            // 
            // flowLayoutPanel2
            // 
            this.flowLayoutPanel2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.flowLayoutPanel2.AutoScroll = true;
            this.flowLayoutPanel2.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.flowLayoutPanel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.tableLayoutPanel2.SetColumnSpan(this.flowLayoutPanel2, 2);
            this.flowLayoutPanel2.Controls.Add(this.pbMap);
            this.flowLayoutPanel2.Location = new System.Drawing.Point(4, 4);
            this.flowLayoutPanel2.Margin = new System.Windows.Forms.Padding(4);
            this.flowLayoutPanel2.Name = "flowLayoutPanel2";
            this.flowLayoutPanel2.Size = new System.Drawing.Size(966, 422);
            this.flowLayoutPanel2.TabIndex = 21;
            // 
            // pbMap
            // 
            this.pbMap.Location = new System.Drawing.Point(4, 4);
            this.pbMap.Margin = new System.Windows.Forms.Padding(4);
            this.pbMap.Name = "pbMap";
            this.pbMap.Size = new System.Drawing.Size(962, 397);
            this.pbMap.TabIndex = 0;
            this.pbMap.TabStop = false;
            this.pbMap.Paint += new System.Windows.Forms.PaintEventHandler(this.pbMap_Paint);
            this.pbMap.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pbMap_MouseDown);
            this.pbMap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pbMap_MouseMove);
            // 
            // pbOthers
            // 
            this.pbOthers.Location = new System.Drawing.Point(4, 4);
            this.pbOthers.Margin = new System.Windows.Forms.Padding(4);
            this.pbOthers.Name = "pbOthers";
            this.pbOthers.Size = new System.Drawing.Size(363, 57);
            this.pbOthers.TabIndex = 0;
            this.pbOthers.TabStop = false;
            this.pbOthers.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pbOthers_MouseDown);
            // 
            // pbTile
            // 
            this.pbTile.Location = new System.Drawing.Point(4, 4);
            this.pbTile.Margin = new System.Windows.Forms.Padding(4);
            this.pbTile.Name = "pbTile";
            this.pbTile.Size = new System.Drawing.Size(243, 57);
            this.pbTile.TabIndex = 2;
            this.pbTile.TabStop = false;
            this.pbTile.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pbTile_MouseDown);
            // 
            // btnAddOtherObj
            // 
            this.btnAddOtherObj.AutoSize = true;
            this.btnAddOtherObj.Image = global::WindowsFormsApplication1.Properties.Resources.file_add1;
            this.btnAddOtherObj.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnAddOtherObj.Location = new System.Drawing.Point(492, 502);
            this.btnAddOtherObj.Margin = new System.Windows.Forms.Padding(4);
            this.btnAddOtherObj.Name = "btnAddOtherObj";
            this.btnAddOtherObj.Size = new System.Drawing.Size(175, 41);
            this.btnAddOtherObj.TabIndex = 6;
            this.btnAddOtherObj.Text = "Add Other Object";
            this.btnAddOtherObj.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnAddOtherObj.UseVisualStyleBackColor = true;
            this.btnAddOtherObj.Click += new System.EventHandler(this.btnAddOtherObj_Click);
            // 
            // btnAddObj
            // 
            this.btnAddObj.AutoSize = true;
            this.btnAddObj.Image = global::WindowsFormsApplication1.Properties.Resources._678092_sign_add_128;
            this.btnAddObj.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnAddObj.Location = new System.Drawing.Point(4, 502);
            this.btnAddObj.Margin = new System.Windows.Forms.Padding(4);
            this.btnAddObj.Name = "btnAddObj";
            this.btnAddObj.Size = new System.Drawing.Size(137, 41);
            this.btnAddObj.TabIndex = 4;
            this.btnAddObj.Text = "Add Object";
            this.btnAddObj.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnAddObj.UseVisualStyleBackColor = true;
            this.btnAddObj.Click += new System.EventHandler(this.btnAddObj_Click);
            // 
            // btnNew
            // 
            this.btnNew.Image = global::WindowsFormsApplication1.Properties.Resources.file_add;
            this.btnNew.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnNew.Location = new System.Drawing.Point(187, 1);
            this.btnNew.Name = "btnNew";
            this.btnNew.Size = new System.Drawing.Size(123, 50);
            this.btnNew.TabIndex = 10;
            this.btnNew.Text = "New Map";
            this.btnNew.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnNew.UseVisualStyleBackColor = true;
            this.btnNew.Click += new System.EventHandler(this.btnNew_Click);
            // 
            // btnLoad
            // 
            this.btnLoad.Image = global::WindowsFormsApplication1.Properties.Resources._12065698321408707419pitr_green_menu_icon_set_1_svg_med;
            this.btnLoad.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnLoad.Location = new System.Drawing.Point(3, 1);
            this.btnLoad.Margin = new System.Windows.Forms.Padding(4);
            this.btnLoad.Name = "btnLoad";
            this.btnLoad.Size = new System.Drawing.Size(177, 52);
            this.btnLoad.TabIndex = 1;
            this.btnLoad.Text = "Load Background";
            this.btnLoad.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnLoad.UseVisualStyleBackColor = true;
            this.btnLoad.Click += new System.EventHandler(this.btnLoad_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(971, 615);
            this.Controls.Add(this.btnSaveTile);
            this.Controls.Add(this.btnSaveMap);
            this.Controls.Add(this.btnSaveMatrix);
            this.Controls.Add(this.tableLayoutPanel2);
            this.Controls.Add(this.lblNewMapUnit2);
            this.Controls.Add(this.lblNewMapUnit1);
            this.Controls.Add(this.txtHeight);
            this.Controls.Add(this.txtWidth);
            this.Controls.Add(this.lblNewMapHeight);
            this.Controls.Add(this.lblNewMapWidth);
            this.Controls.Add(this.btnNew);
            this.Controls.Add(this.btnLoad);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Map Editor";
            this.flpTile.ResumeLayout(false);
            this.flpOthers.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.flowLayoutPanel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pbMap)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbOthers)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbTile)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnLoad;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.PictureBox pbMap;
        private System.Windows.Forms.PictureBox pbTile;
        private System.Windows.Forms.FlowLayoutPanel flpTile;
        private System.Windows.Forms.Button btnAddObj;
        private System.Windows.Forms.Button btnAddOtherObj;
        private System.Windows.Forms.FolderBrowserDialog openFolder;
        private System.Windows.Forms.SaveFileDialog saveFile;
        private System.Windows.Forms.PictureBox pbOthers;
        private System.Windows.Forms.FlowLayoutPanel flpOthers;
        private System.Windows.Forms.Button btnNew;
        private System.Windows.Forms.Label lblNewMapWidth;
        private System.Windows.Forms.Label lblNewMapHeight;
        private System.Windows.Forms.TextBox txtWidth;
        private System.Windows.Forms.TextBox txtHeight;
        private System.Windows.Forms.Label lblNewMapUnit1;
        private System.Windows.Forms.Label lblNewMapUnit2;
        private System.Windows.Forms.Button btnSaveMatrix;
        private System.Windows.Forms.Button btnSaveMap;
        private System.Windows.Forms.Button btnSaveTile;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel2;
    }
}

