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

typedef union
{
    PAWNMETADATA pawnmetadata;
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