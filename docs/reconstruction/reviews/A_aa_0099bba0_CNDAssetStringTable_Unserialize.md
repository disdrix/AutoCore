# Review A (reconstruction fidelity): `aa_0099bba0` CNDAssetStringTable_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099bba0` |
| **VA** | `0x0099bba0`–`0x0099BED5` exclusive (**821 B**) |
| **Canonical name** | `CNDAssetStringTable_Unserialize` |
| **Ghidra name** | `FUN_0099bba0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-J) |
| **Counterpart** | `reviews/B_aa_0099bba0_CNDAssetStringTable_Unserialize.md` |
| **System** | `CNDAssetStringTable` stream load |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 821 B) + plate strings + callee decompiles for role + caller `FUN_0099c1c0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Product `CNDAssetStringTable::Unserialize`: load string-table entries from a stream reader, intern/lookup names, stage temporary string vector; load pyramid structures (resize + nested fill with name→index resolve); destroy temp vector; return success.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-J append) | `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.md` |
| Annotated | `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDAssetStringTable_Unserialize.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0099bba0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0099bba0_CNDAssetStringTable_Unserialize.md` |
| Serialize twin | `0x0099b8e0` / `CNDAssetStringTable_Serialize` |
| Caller | `FUN_0099c1c0` @ `0x0099c23a` |
| Live | decompile + 821 B hex + plate `read_memory` |

---

## 3. Signature (sealed)

```c
// 3 stack formals; RET 0x0C; returns success in AL (=1)
uint8_t CNDAssetStringTable_Unserialize(void* host_table,
                                        void* scratch,
                                        void* stream_reader);
```

| Formal | Source | Conf |
|---|---|---|
| 3 stack args | `C2 0C 00`; caller pushes 3 | **High** |
| stream as EBP | `8B 6C 24 74`; vcall `FF 50 14` | **High** |
| return 1 | `B0 01` before epilogue | **High** |
| host/scratch split | caller `FUN_0099c1c0` formals | **Med-High** |

---

## 4. Control flow (bytes + plates authority)

```
SEH LAB_009b1372; sub esp,0x54
log "CNDAssetStringTable::Unserialize"
zero local StringVec
read u32 nStrings (vtbl+0x14, size 4); log "string table size =%u"
for i in [0,nStrings):
  ctor tmp; FUN_00766fb0; FUN_00989e00; StringVec_PushBack; dtor tmp
read u32 nPyramids; log "pyramids =%u"
FUN_00430540 resize (stride 0x10)
nested pyramid/row reads + FUN_00430600 + FUN_0044ff40 + _stricmp
dtor local StringVec elements; operator_delete buffer
AL=1; ret 0xC
```

| Stage | Match | Conf |
|---|---|---|
| Product plate string | `68 28 B7 A9 00` → `00a9b728` | **High** |
| size / pyramids log plates | `00a9b75c` / `00a9b718` family | **High** |
| String loop + push_back | call sites in hex | **High** |
| Pyramid resize helpers | `FUN_00430540` / `FUN_00430600` | **High** (call) |
| Nested row schema detail | decompiler noisy | **Med** |
| False-noreturn delete | epilogue present | **High** (ignore warning) |

---

## 5. Machine bytes (`read_memory`)

Full body hex (821 B) — see raw W34-J append.

Entry: `6A FF 68 72 13 9B 00`.  
Epilogue: `B0 01 … 83 C4 60 C2 0C 00`.  
Pad: `CC…` @ `0x0099BED5`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0099c1c0` ×1 |
| Callees | log, stream C-string read, intern, push_back, pyramid resize, lower_bound, stricmp, delete |

---

## 7. Gaps

1. Nested pyramid / row field schema not fully dual-sealed (decompiler unreachable-block noise).  
2. Host `CNDAssetStringTable` layout beyond use-sites open.  
3. Helper product plates (`FUN_00766fb0`, `FUN_00989e00`, resize) unowned here.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Product plate, RET-12/return-1 ABI, string-table load stage, and pyramid stage entry points sealed against full-body hex and serialize twin plates → **accept-with-gaps**.
