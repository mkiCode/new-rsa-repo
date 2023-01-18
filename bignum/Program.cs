using System.Security.AccessControl;
using System;
using System.Data;
using System.Numerics;
using System.Globalization;
using System.IO;
using System.Text;

void extended_euclids(
    BigInteger a, 
    BigInteger b, 
    ref BigInteger gcd_result, 
    ref BigInteger x_result, 
    ref BigInteger y_result)
{
    BigInteger x       = BigInteger.Parse("0");
    BigInteger old_x   = BigInteger.Parse("1");
    BigInteger y       = BigInteger.Parse("1");
    BigInteger old_y   = BigInteger.Parse("0");
    BigInteger gcd     = b;
    BigInteger old_gcd = a;
    BigInteger quotient;
    BigInteger temp0;

    while(0!=BigInteger.Compare(gcd,BigInteger.Zero))
    {
       Console.WriteLine("run_loop\n");
       quotient = old_gcd/gcd;

       temp0 = gcd;
       gcd = old_gcd - quotient*gcd;
       old_gcd = temp0;
       
       temp0 = x;
       x = old_x - quotient*x;
       old_x = temp0;

       temp0 = y;
       y = old_y - quotient*y;
       old_y = temp0;
    }
    gcd_result = old_gcd;
    x_result = old_x;
    y_result = old_y;
}
string bnString;

StreamReader reader0 = 
new StreamReader(Environment.CurrentDirectory + "\\m.txt");
StreamReader reader1 = 
new StreamReader(Environment.CurrentDirectory + "\\e.txt");
string fromFile;
StreamWriter writer0 =
new StreamWriter(Environment.CurrentDirectory + "\\d.txt");
 
fromFile = reader0.ReadLine()??"";
Console.WriteLine("M:{0:S}",fromFile,"\n");
BigInteger M = BigInteger.Parse(fromFile, NumberStyles.AllowHexSpecifier);
bnString = M.ToString("D");
Console.WriteLine(bnString);

fromFile = reader1.ReadLine()??"";
Console.WriteLine("E:{0:S}",fromFile,"\n");
BigInteger E = BigInteger.Parse(fromFile, NumberStyles.AllowHexSpecifier);
bnString = E.ToString("D");
Console.WriteLine(bnString);

//BigInteger a = M;
//BigInteger b = E;
BigInteger gcd_result = 0;
BigInteger x_result   = 0;
BigInteger y_result   = 0;

extended_euclids(E, M, ref gcd_result,ref  x_result, ref y_result);
bnString = x_result.ToString("D");
Console.WriteLine("X:{0:S}\n",bnString);
bnString = y_result.ToString("D");
Console.WriteLine("y:{0:S}\n",bnString);

if(BigInteger.IsNegative(x_result))
    x_result = M + x_result;

bnString = x_result.ToString("D");
Console.WriteLine("X:{0:S}\n",bnString);

bnString =  x_result.ToString("X");
Console.WriteLine("X:{0:X}\n", bnString);

writer0.WriteLine("{0:X}\n", bnString);
writer0.Close();

