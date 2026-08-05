# Review A (reconstruction fidelity): `aa_004ac100` MapChild_RebuildHostElemsAndIntGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ac100` |
| **VA** | `0x004ac100`–`0x004ac215` exclusive (**277 B** / `0x115`) |
| **Canonical name** | `MapChild_RebuildHostElemsAndIntGrid_Inferred` |
| **Ghidra name** | `FUN_004ac100` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-L) |
| **Counterpart** | `reviews/B_aa_004ac100_MapChild_RebuildHostElemsAndIntGrid_Inferred.md` |
| **System** | map-child spatial table rebuild |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory` (body + string + call sites). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Outer **orchestrator** on the map-child object (0x3fc class, linked at map `+0xe4f8`):

1. Guard required field `+0x3d8`; else `VOG_DEBUG_STOP` + return 0.
2. Rebuild host 0x28-elem cookie-vector via `FUN_004941b0(host, mapCtx)`.
3. Compute tile dims (signed `/16` of `+0x10`/`+0x14`) → `+0x384`/`+0x388`.
4. Replace zeroed int grid @ `+0x38c`.
5. Follow-up helpers + optional debug branch; return 1.

Not the host rebuild itself; not named after the debug string.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-L re-verify) | `docs/reconstruction/raw/aa_004ac100_FUN_004ac100.md` |
| Annotated | `docs/reconstruction/raw/aa_004ac100_FUN_004ac100.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/MapChild_RebuildHostElemsAndIntGrid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ac100.cpp` |
| Function records | `functions/aa_004ac100_FUN_004ac100.md`, `functions/aa_004ac100_MapChild_RebuildHostElemsAndIntGrid_Inferred.md` |
| Host rebuild peer | `Host_RebuildElem0x28ArrayFromMap_Inferred` (`aa_004941b0`, W30-Q) |
| Callers | `FUN_004ac220`, `FUN_004d9cd0` (bytes at call sites) |
| Live | decompile CF ≡ raw stages; bytes seal ABI/ret4/host load/grid zero |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=mapChild; unused stack arg; RET 4; returns AL 0/1
uint8_t __thiscall MapChild_RebuildHostElemsAndIntGrid_Inferred(void* self, int unused);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| unused | stack (never read; callers push 0) | **High** |
| return | AL 0 fail / 1 ok | **High** |

---

## 4. Control flow (bytes-corrected)

```
if *(this+0x3d8)==0:
  FUN_007a4480(0, "VOG_DEBUG_STOP"); return 0; ret 4

mapCtx = *(this+0x340)
host   = *(mapCtx+0xe898)
FUN_004941b0(host, mapCtx)          // thiscall host; push mapCtx

*(this+0x384) = signed_div16(*(this+0x10))
*(this+0x388) = signed_div16(*(this+0x14))

delete[] *(this+0x38c); *(this+0x38c)=0
grid = new[](dimX*dimY*4); *(this+0x38c)=grid; zero grid

FUN_004abd00(this)
FUN_004aa300(this)
FUN_004930b0(*(mapCtx+0xe894))

if DAT_00b03631: FUN_005c0f40(this)
else:            FUN_005bf720()
DAT_00b03632 = DAT_00b03631
return 1; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Guard + string | **Yes** (string @ `0x00a15844`) | **High** |
| Host rebuild setup | **Yes** (bytes supersede decomp) | **High** |
| Dim / grid rebuild | **Yes** | **High** |
| Follow-ups + flag branch | **Yes** | **High** |
| Body size / ret 4 | **Yes** (bytes) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `56 8B F1 83 BE D8 03 00 00 00 …` |
| Fail epilogue | `32 C0 5E C2 04 00` |
| Host rebuild | `8B 86 40 03 00 00  8B 88 98 E8 00 00  50  E8 …` → `FUN_004941b0` |
| Success epilogues | `B0 01 5E C2 04 00` (both flag branches) |
| Pad | `CC` after `0x004ac214` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Callers | `FUN_004ac220` @ `0x004ac284`; `FUN_004d9cd0` @ `0x004d9ea1`; site `0x00952078` |
| Callees | listed in function record |
| Classification | worker |

---

## 7. Confidence

| Claim | Level |
|---|---|
| Orchestrator CF / ABI / ret 4 | **High** |
| Host load for 004941b0 | **High** |
| Grid sizing/zero | **High** |
| Product map-child English | **Low** |
| Follow-up helper product roles | **Low** (not OWN) |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English / demangle for map-child and `+0x3d8` field.
2. Semantics of `FUN_004abd00` / `FUN_004aa300` / `FUN_004930b0` / flag globals.
3. Runtime / bit-exact / differential.

---

## 9. Verdict

Fidelity pass seals CF, ABI, host-rebuild call, dims, int-grid, and epilogues. Residual product English and non-OWN follow-ups → **accept-with-gaps**.
