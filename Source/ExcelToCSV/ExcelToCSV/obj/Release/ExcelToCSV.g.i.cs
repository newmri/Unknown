﻿#pragma checksum "..\..\ExcelToCSV.xaml" "{8829d00f-11b8-4213-878b-770e8597ac16}" "F152B29AE31FD0084B21FF2D4B58985A997CCACF4FE43F0BF73284813C187540"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using ExcelToCSV;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace ExcelToCSV {
    
    
    /// <summary>
    /// MainWindow
    /// </summary>
    public partial class MainWindow : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 14 "..\..\ExcelToCSV.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ListBox FullPathListBox;
        
        #line default
        #line hidden
        
        
        #line 15 "..\..\ExcelToCSV.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button ExcelToCSVButton;
        
        #line default
        #line hidden
        
        
        #line 16 "..\..\ExcelToCSV.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button ClearFullPathListButton;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/ExcelToCSV;component/exceltocsv.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\ExcelToCSV.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            
            #line 8 "..\..\ExcelToCSV.xaml"
            ((ExcelToCSV.MainWindow)(target)).Closed += new System.EventHandler(this.MainWindow_Closed);
            
            #line default
            #line hidden
            return;
            case 2:
            this.FullPathListBox = ((System.Windows.Controls.ListBox)(target));
            
            #line 14 "..\..\ExcelToCSV.xaml"
            this.FullPathListBox.DragEnter += new System.Windows.DragEventHandler(this.FullPathListBox_DragEnterFullPathListBox);
            
            #line default
            #line hidden
            
            #line 14 "..\..\ExcelToCSV.xaml"
            this.FullPathListBox.Drop += new System.Windows.DragEventHandler(this.FullPathListBox_DragDropFullPathListBox);
            
            #line default
            #line hidden
            return;
            case 3:
            this.ExcelToCSVButton = ((System.Windows.Controls.Button)(target));
            
            #line 15 "..\..\ExcelToCSV.xaml"
            this.ExcelToCSVButton.Click += new System.Windows.RoutedEventHandler(this.ExcelToCSVButton_Click);
            
            #line default
            #line hidden
            return;
            case 4:
            this.ClearFullPathListButton = ((System.Windows.Controls.Button)(target));
            
            #line 16 "..\..\ExcelToCSV.xaml"
            this.ClearFullPathListButton.Click += new System.Windows.RoutedEventHandler(this.ClearFullPathListButton_Click);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}
