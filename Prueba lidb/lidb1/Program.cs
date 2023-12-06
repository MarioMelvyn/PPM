using LiteDB;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lidb1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Open database (or create if doesn't exist)
            using (var db = new LiteDatabase(@"C:\Temp\db1.db"))
            {
                // Get a collection (or create, if doesn't exist)
                var col = db.GetCollection<Customer>("customers");

                // Create your new customer instance
                var customer = new Customer
                {
                    Name = "John Doe",
                    Phones = new string[] { "8000-0000", "9000-0000" },
                    IsActive = true
                };

                // Create your new customer instance
                var customer2 = new Customer
                {
                    Name = "josue suriel",
                    Phones = new string[] { "809-888-8899", "829-889-5469" },
                    IsActive = true
                };


                // Insert new customer document (Id will be auto-incremented)
                col.Insert(customer);
                col.Insert(customer2);

                // Update a document inside a collection
                customer.Name = "Jane Doe";

                col.Update(customer);

                // Index document using document Name property
                col.EnsureIndex(x => x.Name);

                // Use LINQ to query documents (filter, sort, transform)
                var results = col.Query()
                    .Where(x => x.Name.StartsWith("J"))
                    .OrderBy(x => x.Name)
                    .Select(x => new { x.Name, NameUpper = x.Name.ToUpper() })
                    .Limit(10)
                    .ToList();

                // Let's create an index in phone numbers (using expression). It's a multikey index
                col.EnsureIndex(x => x.Phones);

                // and now we can query phones
                var r = col.FindOne(x => x.Phones.Contains("8888-5555"));





            }


            using (var db = new LiteDatabase(@"C:\Temp\db1.db"))
            {
                // Get a collection (or create, if doesn't exist)
                var col = db.GetCollection<Carro>("carro");

                Carro c1 = new Carro();
                c1.Marca = "toyota";
                c1.Modelo = "SUPRA";
                c1.FechaFrabricacion = DateTime.Now;
                c1.Aro = 22;
                c1.IsActive = true;

                col.Insert(c1);

            }
        }

    }
    public class Customer
    {

        public int Id { get; set; }
        public string Name { get; set; }
        public string[] Phones { get; set; }
        public bool IsActive { get; set; }
    }
    public class Carro
    {
        public int Id { get; set; }
        public string Marca { get; set; }
        public string Modelo { get; set; }
        public int Aro { get; set; }
        public DateTime FechaFrabricacion { get; set; }
        public bool IsActive { get; set; }
    }
}