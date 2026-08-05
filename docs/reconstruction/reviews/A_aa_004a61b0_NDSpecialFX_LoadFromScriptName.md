# Review A (reconstruction fidelity): `aa_004a61b0` NDSpecialFX_LoadFromScriptName

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a61b0` |
| **VA** | `0x004a61b0` |
| **Canonical name** | `NDSpecialFX_LoadFromScriptName` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Rep A fidelity + three-rep cross-check) |
| **Counterpart** | `reviews/B_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md` |
| **System** | `client-fx` / special effects scripts |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Load a named special-FX script from disk, parse the first `NDSpecialFX` XML node into an FX object, run post-parse attach/instantiate (`FUN_004a0b90` on the object and `object+0xd5`), and return a usable FX pointer to callers (interact icons, weather, elite chrome, skills, etc.).

**Path rule (memory-verified):**

```text
..\scripts\ + pszName + [optional _nfx.xml]
```

- Prefix string at `0x00a96040` = `..\scripts\` (12 bytes incl. NUL; Windows backslashes).
- If `strstr(pszName, "_nfx.xml") == NULL`, append `_nfx.xml` from `DAT_009ca184..009ca18c` (`_nfx` + `.xml` + `0`).
- If name already contains `_nfx.xml`, leave suffix as provided.
- Open with tag `"NDSpecialFX"` via `NDXml_OpenTaggedDocument` (`0x007999c0`).

**Plate comment correction:** prior plate said `+ ".xml"`; bytes prove append is **`_nfx.xml`**, not bare `.xml`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a61b0_NDSpecialFX_LoadFromScriptName.md` |
| Annotated | `docs/reconstruction/raw/aa_004a61b0_NDSpecialFX_LoadFromScriptName.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_LoadFromScriptName.cpp` |
| Alt clean | `docs/reconstruction/reconstructed-exact/FUN_004a61b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a61b0_NDSpecialFX_LoadFromScriptName.md` |
| Live Ghidra | `decompile_function` + `read_memory` + basic pcode + callees/xrefs (2026-07-29) |

---

## 3. Three independent reps (record)

### Rep 1 — Decompiler body (Ghidra pseudocode)

```
SEH frame; FUN_00799940()           // NDXml session / stack-doc ctor
zero path buffer (~0x102 bytes from local_120+2)
memcpy-ish 12 bytes "\..\scripts\" into path
append pszName (dword + tail copy)
if !strstr(pszName,"_nfx.xml"): append "_nfx.xml"
iVar5 = NDXml_OpenTaggedDocument(path, "NDSpecialFX")
if iVar5==0 && local_12c > 0:
  piVar3 = FUN_00799900(0)          // first node
  if !piVar3: FUN_007a4480(0,"VOG_DEBUG_STOP")
  else:
    local_139[0]=0
    pvVar4 = FUN_004a4fa0(node, local_124, local_139, pszName)  // parse FX
    node->vtbl[+8](node)            // release node
    if pvVar4:
      FUN_004a0b90(pvVar4, pvVar4+0xd5, 1, -1, unused)
      FUN_004b85d0(); FUN_004b99c0(); operator_delete(pvVar4)  // SEE GAP
FUN_007989b0(); restore ExceptionList
return NULL                         // SEE GAP
```

### Rep 2 — Constants via `read_memory`

| Addr | Bytes / string | Role |
|---|---|---|
| `0x00a96040` | `2e 2e 5c 73 63 72 69 70 74 73 5c 00` → `..\scripts\` | Path prefix |
| `0x009ca184` | `5f 6e 66 78 2e 78 6d 6c 00` → `_nfx.xml` | Default suffix |
| `0x009ca178` | `NDSpecialFX` | Open tag |
| `0x00a15844` | `VOG_DEBUG_STOP` | Missing-node assert log |

### Rep 3 — Pcode / caller contract

| Observation | Evidence |
|---|---|
| Fail path returns **0 in EAX** | BB `004a62c3`: `COPY 0 → EAX`, `RETURN` after `FUN_007989b0` |
| Success BB `004a6312` | calls `004a0b90` → `004b85d0` → `004b99c0` → `operator_delete@00489822` then modeled as **RETURN without value** (noreturn mislabel) |
| Callers require live non-null | e.g. weather `+0x104`, interact icons, `generic_elite`, skills — store/check return |
| `flags` (arg2) | **Never referenced** in body or pcode of this VA |
| `unused` (arg3) | Passed as 5th arg to `FUN_004a0b90` |

**Three-rep consensus:** path/open/parse CF is **High**. Success **return value / ownership** of `pvVar4` after `FUN_004a0b90` is **Open / decompiler-broken** — clean/raw “always null + delete template” conflicts with 39 live call sites.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__cdecl` `void*(char* name, int flags, int unused)` | **High** | Ghidra prototype + stack params |
| Path = `..\scripts\` + name + optional `_nfx.xml` | **High** | `read_memory` + strstr gate |
| Tag open `"NDSpecialFX"` | **High** | String + `NDXml_OpenTaggedDocument` |
| First node via `FUN_00799900(0)` | **High** | Body |
| Parse via `FUN_004a4fa0` | **High** | Callee; event-type enum inside parser (out of own-VA scope) |
| Post-parse `FUN_004a0b90(fx, fx+0xd5, 1, -1, unused)` | **High** | Call site; clone/instantiate family |
| Node release vtbl+8 | **High** | COM/XML node Release pattern |
| `flags` unused in this function | **High** | No refs; callers still pass 0/2/4/−1 |
| Always returns null on success | **Low / rejected by callers** | Decompiler + noreturn `operator_delete` artifact |
| `FUN_004b85d0` / `FUN_004b99c0` = FX dtor helpers | **Medium** | Patterns elsewhere; thiscall via ECX not shown in C |
| `local_12c` = open node count / success side channel | **Medium** | Compared `> 0` with open status 0 |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + path build + suffix | **Yes** |
| OpenTaggedDocument gate | **Yes** |
| Parse + node release + 004a0b90 | **Yes** |
| Fail → cleanup → null | **Yes** |
| Success return pointer | **No invent; raw/clean both wrong vs callers** |

Clean ≡ raw decompiler CF. Do **not** invent a corrected return until epilogue is recovered (tiny disasm or runtime) — gap is explicit.

---

## 6. Signature / callees (own VA surface)

```c
void * __cdecl NDSpecialFX_LoadFromScriptName(char *pszName, int flags, int unused);
```

| Callee | VA | Role (inferred) |
|---|---|---|
| `FUN_00799940` | `0x00799940` | NDXml stack session ctor |
| `NDXml_OpenTaggedDocument` | `0x007999c0` | Open path with root tag |
| `FUN_00799900` | `0x00799900` | Get first / indexed node |
| `FUN_004a4fa0` | `0x004a4fa0` | Parse NDSpecialFX node → 0x240 object |
| `FUN_004a0b90` | `0x004a0b90` | Instantiate/clone from template (+0xd5, mult=1, filter=−1) |
| `FUN_004b85d0` / `FUN_004b99c0` | `0x004b85d0` / `0x004b99c0` | Likely FX resource teardown |
| `FUN_007989b0` | `0x007989b0` | NDXml session dtor |
| `FUN_007a4480` | `0x007a4480` | Debug log (`VOG_DEBUG_STOP`) |
| `strstr` / `operator_delete` | CRT | Suffix test / free |

---

## 7. Gaps / open

1. **Success return recovery** — must return non-null usable FX; epilogue after `004a0b90` needs re-lift (prefer tiny read of ret path, not full disasm pass).
2. Whether `operator_delete(pvVar4)` frees the **template** after clone (and return is clone), or is pure decompiler garbage.
3. Semantic name of `flags` (unused here; maybe reserved for loader policy elsewhere).
4. `local_124` / `local_139` roles in parser (event-type out + counter).
5. Server vs client: load path under `..\scripts\` is **client-side asset**.

**Verdict:** **accept-with-gaps** — path/open/parse contract solid; ownership/return residual blocks bit-exact port of success epilogue.
