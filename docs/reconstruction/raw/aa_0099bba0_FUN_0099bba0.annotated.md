# Annotated low-level: CNDAssetStringTable_Unserialize

| Field | Value |
|---|---|
| Stable ID | `aa_0099bba0` |
| VA | `0x0099bba0`–`0x0099BED5` exclusive (**821 B** / `0x335`) |
| System | `CNDAssetStringTable` stream load |
| Date | 2026-07-29 (W34-J dual A/B) |
| Ghidra | `FUN_0099bba0` |

## Machine-level notes

- Product plate string @ `0x00a9b728`: **`CNDAssetStringTable::Unserialize`**.
- Companion serialize @ `0x0099b8e0` (registry name `CNDAssetStringTable_Serialize`).
- ABI: **three stack formals**, **`RET 0x0C`**; returns **1** in AL (success).
- Reader object held in **EBP**; stream primitive = vtbl[+0x14] (size-bearing read; used with size=4 for counts and for C-string bytes via `FUN_00766fb0` which also uses vtbl[+0x10]/[+0x14]).
- Local `vector<basic_string>` accumulates table strings (stride 0x1c) then is destroyed before return.
- Pyramid section uses elem stride **0x10** resize helpers `FUN_00430540` / `FUN_00430600`.
- Ghidra emits many “unreachable block” warnings and false-noreturn on `operator_delete`; epilogue `B0 01 … C2 0C 00` proves return-1 path is live.
- Nested pyramid / lower_bound / stricmp fill is **partially sealed** (call sites present in hex); full row schema not dual-owned.

## Staged CF (annotated)

```
SEH LAB_009b1372; sub esp,0x54; save ebx/ebp/esi/edi
EBP = stream reader (stack formal)

FUN_007a4480(..., "CNDAssetStringTable::Unserialize")
zero local StringVec shell (begin/end/cap)

// --- string table ---
reader.vtbl[+0x14](dst, 4)  → nStrings
FUN_007a4480(..., "string table size =%u", nStrings)
for i in 0..nStrings-1:
  basic_string_ctor(tmp)
  FUN_00766fb0()            // read NUL-terminated into tmp (ESI=reader, EDI=tmp)
  FUN_00989e00(...)         // intern/lookup into host table object
  FUN_004301f0(localVec, tmp)  // StringVec_PushBack
  basic_string_dtor(tmp)

// --- pyramids ---
reader.vtbl[+0x14](dst, 4)  → nPyramids
FUN_007a4480(..., "pyramids =%u", nPyramids)
FUN_00430540(hostPyramidVec, nPyramids, ...)  // resize stride 0x10
// nested: for each pyramid / row:
//   read counts; FUN_00430600 reshape
//   FUN_0044ff40 lower_bound + _stricmp resolve names against string table
//   write resolved indices / slots into host

// cleanup local string vec (dtor 0x1c steps + operator_delete)
AL = 1; ret 0x0C
```

## Callers

| Site | Context |
|------|---------|
| `FUN_0099c1c0` @ `0x0099c23a` | Loads local table object (`PTR_FUN_00a983b4`), calls unserialize with stream `param_1` |

## Gaps

- Exact three formal roles beyond (host table*, scratch/out*, reader*) — caller `FUN_0099c1c0` maps them but host field layout open.
- Nested pyramid row schema / `FUN_0044ff40` comparator plate not dual-owned.
- `FUN_00766fb0` / `FUN_00989e00` product plates open (helpers).
- Runtime / bit-exact / differential open.
