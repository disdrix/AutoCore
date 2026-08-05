# Annotated low-level: FUN_005d4fd0 → Object_UnloadGraphics_Entry_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005d4fd0` |
| VA | `0x005d4fd0`–`0x005d5025` exclusive (**85 B**) |
| System | client / object graphics lifecycle |
| Date | 2026-08-04 (W37-AB) |
| Canonical | `Object_UnloadGraphics_Entry_Inferred` (Ghidra `FUN_005d4fd0`) |

## Machine-level notes

- **Logged entry** for unload-graphics, DATA-installed in **8** class vtables (no direct CODE callers).
- ECX is an **MI-adjusted** object pointer (same family as W31-T core). Negative offsets `-0x3c` / `-0x40` are vbtable / primary-base adjustments, not stack.
- Flow:
  1. Resolve optional name record: `*(root + 0x6c)` via vbtable; null → nameId **`-1`**, else **`*(rec+0x34)`**.
  2. Root **`vtbl+0x160(nameId)`** → value used as log argument (string-ish for `%s`).
  3. `FUN_007a4480(-1, "UnloadGraphics on %s (%d)", arg)`.
  4. **`Object_UnloadGraphics_Inferred`** (`FUN_005825d0`, W31-T) with same ECX.
  5. **Tail** to base method: `LEA ECX,[this-0x40]; JMP [*(this-0x40)+4]` — decompiler “call then return” is wrong; bytes are **JMP**.
- Format string contains `%s` and `%d` but stack only supplies **one** intentional vararg after format (`ADD ESP,0x10` also drops leftover vcall push). Residual mismatch sealed as gap.

## Pseudocode (annotated)

```c
// __thiscall; ECX = MI object*; void; ends in tail JMP (no RET)
void __fastcall Object_UnloadGraphics_Entry_Inferred(ObjectMi* self)
{
  void* rootAdj = /* vbtable *(self-0x3c)+4 */;
  int* nameRec = *(int**)((char*)rootAdj + (char*)self + 0x6c); // decompiler form
  uint32_t nameId = (nameRec == 0) ? 0xFFFFFFFFu : nameRec[0x34/4];

  void* root = (char*)self + /* adj from vbtable -0x3c path */;
  // thiscall: this = root, arg = nameId
  const char* nameOrToken = root->vtbl->fn_160(nameId);

  FUN_007a4480(0xFFFFFFFF, "UnloadGraphics on %s (%d)", nameOrToken);
  Object_UnloadGraphics_Inferred(self);   // FUN_005825d0

  // tail, not call+ret:
  Base* base = (Base*)((char*)self - 0x40);
  return base->vtbl->fn_04();             // JMP [vtbl+4]
}
```

## Related

| Unit | VA | Role |
|------|-----|------|
| `Object_UnloadGraphics_Inferred` | `0x005825d0` | core body (W31-T) |
| `Object_SetMissionStateFx_Inferred` | `0x00518370` | nested from core, state 3 |
| Log helper | `FUN_007a4480` | levelled message |

## Open questions

- Product names for `vtbl+0x160`, name record `+0x6c`/`+0x34`.
- Why format has two conversions but one vararg.
- Full class atlas for 8 DATA vtable installs.
- Runtime / bit-exact / differential.
