// Supported with union (c) 2020 Union team

// User API for zCPar_SymbolTable
// Add your methods here

void PostDefineExternal_Union( zCPar_Symbol* external );
void Load_Union( zFILE* f );
int Insert_Union( zCPar_Symbol* sym );
int InsertAt_Union( zCPar_Symbol* sym, int alloc );
int GetIndex_Safe( zSTRING const& );
int __fastcall SearchNearest( const zSTRING& name, int low, int high );
int __fastcall Search_Union( const zSTRING& name, int low, int high );