# Review A (reconstruction fidelity): `aa_00516720` Object_SetDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516720` |
| **VA** | `0x00516720`–`0x00516899` exclusive (**377 B** / `0x179`) |
| **Canonical name** | `Object_SetDisplayName_Inferred` |
| **Ghidra name** | `FUN_00516720` |
| **Prior scaffold** | `FUN_00516720` / `Named_CalleeOf_CVOGCreature_PostCreateFromPacket_00516720` (2026-07-23) |
| **Rejected misname** | permanent bare `FUN_*`; skill-specific plate; creature-only callee alias as final |
| **Review date** | `2026-08-05` (R10-031 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00516720_Object_SetDisplayName_Inferred.md` |
| **System** | object-identity / display-name (partition parent `0x0051b230` skills-abilities residual) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_by_address` + callee `batch_decompile`. **No** `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

Shared **object display-name setter** on the cloned-object hierarchy:

1. On non-null input, free prior owned string at `*(this+0x158)` and clear it.
2. If compose gates pass (`vtbl+0x60`, host `+0xA4`, name-manager `FUN_004ce940`), build a composed display name via `FUN_005146a0` (mods / prefix / `[$swap]`) and store it at `+0x158`.
3. Else compare input against the template default name; store a heap copy only when it differs (`strncmp` n=`0x41`) and `strlen > 1`; otherwise leave `+0x158` NULL (UI uses template default).
4. Null input returns immediately **without** clearing `+0x158`.

```text
Object_SetDisplayName_Inferred(self, nameOrNull)
  if nameOrNull == NULL: return          // preserve +0x158
  free(+0x158); +0x158 = NULL
  if vtbl+0x60() && +0xA4 && NameMgr():
       compose = FUN_005146a0(... cap 0x5A)
       +0x158 = strdup(compose); return
  default = templateName(+0xA8 → FUN_004eb240 → wide→MB)
  if name != default[0..0x41) && strlen(name) > 1:
       +0x158 = strdup(name)
  // else leave NULL
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R10 re-verify append) | `docs/reconstruction/raw/aa_00516720_FUN_00516720.md` |
| Annotated | `docs/reconstruction/raw/aa_00516720_FUN_00516720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetDisplayName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00516720.cpp` |
| Function records | `functions/aa_00516720_FUN_00516720.md`, `functions/aa_00516720_Object_SetDisplayName_Inferred.md` |
| Live Ghidra | decompile + analyze_complete + callers/xrefs + assembly context + read_memory + body bounds |
| Parent dual context | `Object_CreateFromEmbeddedCbid_Inferred` `0x0051b230` (name copy site `0x0051b282`) |
| Compose callee | `FUN_005146a0` `0x005146a0` (`[$swap]`, prefix composition) |

---

## 3. Signature (sealed)

```c
// __thiscall; bare stack cleanup via RET 4
void __thiscall Object_SetDisplayName_Inferred(void *self, char *nameOrNull);
// ECX = self; [ESP+4] = nameOrNull; return void
```

| Item | Evidence |
|---|---|
| Body size | 377 B; range `00516720`–`00516899` exclusive (`get_function_by_address`) |
| This bind | `MOV ESI, ECX` after name null-check |
| Stack formal | `MOV EBP, [ESP+0x90]` post `SUB ESP,0x88` |
| Epilogue | `ADD ESP,0x88` / `RET 4` (compose early-out + fallback end) |
| Name field | `[ESI+0x158]` free / store (`operator_delete[]` / `operator_new[]`) |
| Host gate | `CMP [ESI+0xA4], EDI` |
| Template src | `MOV ECX, [ESI+0xA8]` → `FUN_004eb240` |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Prolog `SUB ESP,0x88` + save name EBP | bytes | **Confirmed** |
| Null name far-return (no free) | `CMP EBP,EDI` / `JZ` | **Confirmed** |
| Free/clear `+0x158` | `MOV EAX,[ESI+0x158]` / `operator_delete[]` / store 0 | **Confirmed** |
| Entry strlen → `[ESP+0x0C]` | scan + `MOV [ESP+0x0C],EAX` | **Confirmed** |
| `CALL [vtbl+0x60]` gate | `CALL [EAX+0x60]` | **Confirmed** |
| Host `+0xA4` gate | `CMP [ESI+0xA4],EDI` | **Confirmed** |
| `FUN_004ce940` gate | call + `TEST EAX` | **Confirmed** |
| Compose `PUSH 0x5A` + `FUN_005146a0` | site bytes | **Confirmed** |
| `strdup` composed → `+0x158` + `RET 4` | early-out path | **Confirmed** |
| Fallback `FUN_004eb240` / wide→MB / `strncmp` n=`0x41` | decompile ≡ callees | **Confirmed** |
| Store custom only if differ && len>1 | branch to `operator_new[]` | **Confirmed** |
| Live decompile CF ≡ prior raw CF | re-verify append | **Confirmed** |

---

## 5. Callers / callees

**Callers (12 plates; 16 UNCONDITIONAL_CALL xrefs):**  
`FUN_004cf120`, `FUN_0051b230`, `CVOGCreature_PostCreateFromPacket`, `Vehicle_applyCreatePacket`, `FUN_004f3e40`, `FUN_00503780`, `FUN_004c82b0`, `FUN_00563ab0`, `FUN_00568250`, `FUN_00569bc0`, `FUN_005feb50`, `FUN_005fecb0`, plus sites `0x005a6d32`, `0x006097d5`, `0x0086b82e`, `0x0086d316`.

**Parent site seal:** `0x0051b282` — `MOV ECX,ESI` (new obj); `PUSH [EDI+0x158]` (host name) → copies host display name onto clone.

**Callees:** `operator_delete[]`, `operator_new[]`, vtbl+0x60, `FUN_004ce940`, `FUN_007a69d0`, `FUN_007a6880`, `FUN_005146a0`, `FUN_004eb240`, `PTR_FUN_00af8c9c` / `FUN_00403450`, `strncmp`, `free`.

---

## 6. Confirmations

| # | Claim | Status |
|---|---|---|
| 1 | thiscall, one stack formal, `RET 4` | **Confirmed** |
| 2 | Owned name field at `+0x158` | **Confirmed** |
| 3 | Null name does not clear field | **Confirmed** |
| 4 | Compose path via `FUN_005146a0` cap `0x5A` | **Confirmed** |
| 5 | Fallback custom-only-if-differs-and-len>1 | **Confirmed** |
| 6 | Multi-caller shared object helper (not creature-only) | **Confirmed** |
| 7 | Decompile CF ≡ raw CF ≡ image role | **Confirmed** (size/ABI via bytes) |

---

## 7. Residual gaps

- Product MSVC / PDB English for this VA.
- Product name for vtbl `+0x60` (mod-count vs slot-count vs “has affixes”).
- Concrete type of `FUN_004ce940` singleton.
- Full CString layout of fallback MB conversion (SSO pointer slot typing).
- Runtime Confirmed / bit-exact / differential (no Launcher).

---

## 8. Verdict

Structural role, ABI (`thiscall`/`RET 4`), field `+0x158`, compose vs custom branches, and multi-caller graph sealed from decompile + `read_memory` + call sites. Product English open → **accept-with-gaps**.
