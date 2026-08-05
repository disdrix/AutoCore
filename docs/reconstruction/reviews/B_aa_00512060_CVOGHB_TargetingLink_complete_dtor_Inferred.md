# Review B (skeptical / adversarial): `aa_00512060` CVOGHB_TargetingLink_complete_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512060` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-A) |
| **Counterpart** | `reviews/A_aa_00512060_CVOGHB_TargetingLink_complete_dtor_Inferred.md` |
| **Verdict** | **accept** (trivial CF; residual is product name only) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the scalar-deleting dtor (`flags & 1` + `operator_delete`) | **Falsified** — no stack arg, no delete; scalar is `0x00512070` |
| 2 | Body only sets vtbl and returns (no detach) | **Falsified as complete story** — tail into `FUN_00508390` which may detach |
| 3 | Intermediate vtbl write is the final vtbl after dtor | **Falsified** — base path overwrites with `009cdab0` |
| 4 | Class is `CVOGHBPlayerTargetingLink` | **Falsified as sole class** — vtbl imm is base family `009cdfb0`; derived uses thunk of same body |
| 5 | Same unit as `thunk_FUN_00512060` address | **Falsified** — thunk is `0x0051b890` (JMP here); different VA |
| 6 | `__stdcall` / `ret 4` ABI | **Falsified** — ECX this; bare tail, no `c2 04 00` |
| 7 | Drop `_Inferred` because role obvious | **Reject** — family RTTI/product string not sealed on this VA (ctor dual also `_Inferred`) |
| 8 | Invent free of linked partner HB in this body | **Falsified** — only vtbl write + tail; partner work is in base detach if any |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 11-byte complete-dtor body | **High** | inventing scalar delete double-frees |
| Tail to base dtor | **High** | missing detach / wrong teardown order |
| Distinct from `00512070` | **High** | alias collapse |
| Family name `_Inferred` | **High** | overclaim product class string |

---

## 3. Cross-check against raw + bytes

```
CVOGHB_TargetingLink_complete_dtor_Inferred:
  mov  dword ptr [ecx], offset PTR_FUN_009cdfb0   ; c7 01 b0 df 9c 00
  jmp  FUN_00508390                               ; e9 25 63 ff ff
```

Any clean plate with `operator_delete`, stack `flags`, or `ret 4` is **wrong** for this VA (that is the scalar wrapper).

Sibling dual for `00512070` already depends on this complete body — keep names aligned (`complete_dtor` vs `scalar_dtor`).

---

## 4. Surviving contract for AutoCore

```c
// Port: complete dtor only
void CVOGHB_TargetingLink_complete_dtor(void *thisHb) {
  *(void **)thisHb = /* family vtbl 009cdfb0 */;
  CVOGHBBase_complete_or_detach_path(thisHb); // FUN_00508390
}

// Scalar path (other VA): complete_dtor(this); if (flags&1) operator_delete(this);
// Do not implement partner-unlink English here beyond what FUN_00508390/FUN_005085b0 own.
```

---

## 5. Open questions

1. PDB / mangled complete-dtor symbol.
2. Exact English for `FUN_005085b0` detach (not owned).

**Verdict:** **accept**
