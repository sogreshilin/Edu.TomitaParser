#encoding "utf-8"
#GRAMMAR_ROOT S

PersonName -> Word<h-reg1, ~fw, nc-agr[1]> Word<h-reg1, nc-agr[1]>*;

FilmName -> Word<h-reg1, quoted>;
FilmName -> Word<h-reg1, l-quoted> Word* Word<r-quoted>;
OriginalFilmName -> Word<h-reg1, lat> Word<lat>*;

Year -> AnyWord<kwtype="Date">;
AtThatYear -> 'в' Year interp (FilmFact.Year) ('год'<gram="пр">);

Genre -> Word<kwtype="Genre"> interp (FilmFact.Genre);
Film -> 'фильм';
Descr -> Adj<gnc-agr[1]>* Genre<gnc-agr[1]>;
Descr -> Adj<gnc-agr[1]>* Film<gnc-agr[1]>;

Director -> ('режиссер'<nc-agr[1]>) PersonName<gram="род", nc-agr[1]> interp (FilmFact.Director);
Director -> Comma 'снять'<gram="прич"> ('режиссер'<nc-agr[1]>) PersonName<gram="твор", nc-agr[1]> interp (FilmFact.Director) (AtThatYear);
DescrDirector -> Descr (Year interp (FilmFact.Year)) ('год'<gram='род'>) (Director);

S -> DescrDirector FilmName interp (FilmFact.Title::not_norm) (LBracket) (OriginalFilmName interp (FilmFact.OriginalTitle)) (RBracket);
S -> FilmName interp (FilmFact.Title::not_norm) (LBracket) (OriginalFilmName interp (FilmFact.OriginalTitle)) (RBracket) (Hyphen) DescrDirector;
