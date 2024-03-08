#ifndef         __FRUIT_HPP__
    #define     __FRUIT_HPP__

    #include <iostream>

    class       Fruit
    {
        public:
            Fruit(void);
            ~Fruit(void);

            std::string         getName(void) const;
            int                 getVitamins(void) const;

            void                setName(std::string name);
            void                setVitamins(int vitamins);
        private:
            std::string         _name;
            int                 _vitamins;
    };
#endif //       !__FRUIT_HPP__