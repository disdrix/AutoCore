# Review A (reconstruction fidelity): `aa_005194f0` Gfx_BindMatDiffuseAmbientEmissive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005194f0` |
| **VA** | `0x005194f0` |
| **Canonical name** | `Gfx_BindMatDiffuseAmbientEmissive_Inferred` |
| **Review date** | `2026-08-04` (WQ-009 residual WQ9R-F) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_005194f0_Gfx_BindMatDiffuseAmbientEmissive_Inferred.md` |
| **System** | graphics / material FX (residual under WQ-009 partition) |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind per-shader **material color triples** from a packed float4 bank onto effect objects:

1. Count shader entries at `host+0xc0/+0xc4` (dword stride).
2. Count color float4s at `colorVec+4/+8` (stride `0x10`).
3. Require `shaderCount * 3 == colorCount` (else `VOG_DEBUG_STOP` log, continue).
4. For each shader `i`, call binder `FUN_009700f0` three times with names `MatDiffuse` / `MatAmbient` / `MatEmissive` and color slots at `begin + i*0x30 + {0,0x10,0x20}`.
5. Resize color vector to **0** (clear bank after apply).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005194f0_FUN_005194f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005194f0_FUN_005194f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_BindMatDiffuseAmbientEmissive_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_005194f0_Gfx_BindMatDiffuseAmbientEmissive_Inferred.md` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x005194f0` (2026-08-04) — ≡ raw |
| Bytes | `read_memory` @ entry + epilogue; Capstone linear decode of body; call-site `get_assembly_context` |
| Callers | `FUN_0051b310` @ `0051b345`; `FUN_004c5510` @ `004c5553` |

**Not performed:** `disassemble_bytes`, Launcher, live CE, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| cdecl, 2 stack args, void (`ADD ESP,8` / `RET`) | **High** | both call sites |
| Body `0x005194f0`–`0x00519657` (359 B) | **High** | Ghidra function bounds + `CC` pad |
| Shader vector `+0xc0/+0xc4`, `>>2` | **High** | bytes + decompile |
| Color vector begin/end `+4/+8`, `>>4` | **High** | bytes + `FUN_0051def0` peer |
| `count*3` assert → `VOG_DEBUG_STOP` | **High** | `lea ecx,[ecx+ecx*2]; cmp` |
| Names `MatDiffuse`/`MatAmbient`/`MatEmissive` | **High** | imm pushes `0x00a2f8cc/c0/b4`; string dump |
| Binder ECX = `*(hostVec[i]) + 0x20` | **High** | Capstone: `mov ecx,[eax+esi]; add ecx,0x20` |
| Color stride group `0x30` (3×float4) | **High** | `add edi,0x30` per iter |
| Epilogue `FUN_0051def0(this=colorVec, size=0)` + fill `(0,0,0,1)` | **High** | `push 0; mov ecx,ebp; call`; `g_flOne` @ `0x00a0f2a0` = 1.0f |
| Product class English for host | **Low** | Inferred from Mat* strings only |
| Skill-bank role | **N/A / reject** | graphics bind; residual address only |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| count / assert / loop / clear | **Yes** |
| Binder this = entry+0x20 | **Bytes win** over decompile string-as-this |
| Resize(0) after loop | **Bytes win** over decompile 5-arg call shape |

---

## 5. Call graph (this unit)

**Callees:** `FUN_007a4480`, `FUN_009700f0` (×3/iter), `FUN_0051def0`.  
**Callers:** `FUN_0051b310`, `FUN_004c5510`.

---

## 6. Gaps / open

1. Product type of `*(hostVec[i])` and field `+0x20`.
2. Full dual of `FUN_009700f0` / `FUN_0051def0`.
3. Owner object layout for color bank at `this+0x144` (caller residual).
4. Runtime / bit-exact.

---

## 7. Verdict

**accept-with-gaps** — material triple bind CF + ABI + string names sealed; product type names open.
