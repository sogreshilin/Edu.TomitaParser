#encoding "utf-8"

OrgDescr -> 'магазин';

// магазин (кого?) мадам Малкиной
// магазин (чего?) приколов Зонко
LastName -> AnyWord<h-reg1>;
WhosStore -> Word<gram="gen", gnc-agr[1]> LastName<gnc-agr[1]>;
S -> OrgDescr WhosStore interp (Org.OrgName::not_norm);

// любое название в ковычках
Name -> Word<h-reg1> (Word*);
S -> Name<quoted> interp (Org.OrgName::not_norm);
