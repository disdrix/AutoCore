# Review A (reconstruction fidelity): `aa_00439a80` Client_ApplyPairRelativeTransform

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439a80` |
| **VA** | `0x00439a80` |
| **Body** | `0x00439a80`–`0x00439da3` |
| **Canonical name** | `Client_ApplyPairRelativeTransform` |
| **Prior / alias** | `FUN_00439a80`; parent-seed `Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_00439a80` (**incomplete**) |
| **Review date** | `2026-07-29` (W19-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00439a80_Client_ApplyPairRelativeTransform.md` |
| **System** | client gfx / special-event pair attach |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs`, `analyze_function_complete` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Pair-object relative transform bind** driven by an **EDI-held 4-pointer context**. Pulls A/B transforms (with optional helper sides), builds / inverse-conjugates a quaternion when norm² is stable, projects via `Math_Mat4TransformPoint3_Project`, applies mode-`3` slots onto object B.

Multi-caller worker (TeleportIn, Respawn Update, attach helpers) — **not** TeleportIn-only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00439a80_FUN_00439a80.md` |
| Annotated | `docs/reconstruction/raw/aa_00439a80_FUN_00439a80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ApplyPairRelativeTransform.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00439a80.cpp` |
| Function record | `docs/reconstruction/functions/aa_00439a80_Client_ApplyPairRelativeTransform.md` |
| Live decompile | ≡ raw CF |
| Live entry bytes | `55 8b ec 83 e4 f0 81 ec 28 03 00 00 53 8b 5f 0c 56 8b 77 04 …` |
| Live eps | `0x00a240ec`=`1e-6f`; `0x00aaa640`=`-1e-6f` |

---

## 3. Byte / ABI seal

```
push ebp / mov ebp,esp / and esp,-16 / sub esp,0x328
push ebx; mov ebx,[edi+0xc]   ; optB
push esi; mov esi,[edi+4]     ; optA
… body …
pop esi; pop ebx; mov esp,ebp; pop ebp; ret   ; c3
```

| Claim | Evidence | Conf |
|---|---|---|
| EDI pair ctx | prologue `[edi+0xc]`/`[edi+4]` + body `*unaff_EDI` / `[2]` | **High** |
| Bare ret | epilogue `c3` | **High** |
| Stack frame 0x328 + 16-align | `81 ec 28 03 00 00` + `83 e4 f0` | **High** |
| Quaternion inverse path | decomp + same eps as Mat4 project | **High** |
| Project callee | `FUN_0076f6e0` sealed sibling | **High** |
| 8 callers | xrefs | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| optA null → vtbl+8(-1) else helper path | **Yes** |
| objB seed (0,0,0,1) + vtbl +0x14/+0x18/+0x34 | **Yes** |
| optB null/helper mirror | **Yes** |
| \|q\|² + conditional inverse-conjugate | **Yes** |
| 72e50 + 76f6e0 + compose + mode-3 apply | **Yes** |
| Single return | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-caller pair bind | **High** | 8 xrefs |
| EDI layout slots | **High** | prologue + body |
| Quat inverse math | **High** | conjugate / \|q\|² |
| Product class / vtbl English | **Open** | structural name only |
| Sibling callee product names | **Open** | FUN_* residual |
| Runtime / bit-exact | **Open** | deferred |

---

## 6. Gaps / open

1. Product/PDB symbol.
2. Exact C++ type of EDI pack and vtbl slot English (`+8/+10/+14/+18/+34`).
3. Full semantics of `FUN_00972cc0` / `72e50` / `73030` / `40cf90` / `40d1a0` (out of owned scope).
4. Runtime / differential.

**Verdict:** **accept-with-gaps**
