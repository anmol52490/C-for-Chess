typedef enum
{
    NONE,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    KING,
    QUEEN
} PIECE;

typedef enum
{
    BLACK,
    WHITE,
    NONES
} COLOR;

typedef enum
{
    FALSE,
    TRUE
} ENPASSANT;

// typedef enum {TRUE, FALSE} PAWNDOUBLE;

typedef struct
{
    bool enpassant;
    bool pawndouble;
} PAWNMETADATA;

typedef struct {
    bool queenfirstmove;
}QUEENMETADATA;

typedef struct{
    bool knightfirstmove;
}KNIGHTMETADATA;

typedef struct{
    bool bishopfirstmove;
}BISHOPMETADATA;

typedef struct 
{
    bool rookcastle;
} ROOKMETADATA;

typedef union
{
    PAWNMETADATA pawnmetadata;
    ROOKMETADATA rookmetadata;
    KNIGHTMETADATA knightmetadata;
    BISHOPMETADATA bishopmetadata;
    QUEENMETADATA queenmetadata;
} METADATA;


typedef struct
{
    PIECE piece;
    COLOR color;
    METADATA metadata;
} DATA;

typedef struct
{
    DATA data;
} square;

DATA empty = {
    .piece = NONE,
    .color = NONES,
};
const char *piece_list[] = {
    " ",
    "P",
    "R",
    "K",
    "B",
    "Ki",
    "Q"};