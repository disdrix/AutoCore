# Review B (skeptical / adversarial): `aa_005c6720` TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6720` |
| **VA** | `0x005c6720` |
| **Canonical name** | `TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_005c6720_TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.md` |
| **System** | track-manager payload ↔ object match |
| **Live tools** | Independent decompile + `read_memory` + W37-T caller dual + TFID peer |
| **Verdict** | **accept-with-gaps** — accept dual-mode leaf; reject scaffold product name and “pointer-only” claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Match is raw pointer compare only | **Falsified** — TFID triple path is primary when ids valid |
| 2 | Always TFID-only (no pointer path) | **Falsified** — invalid×invalid uses `payload+0x10 == object` |
| 3 | Invalid test is `lo == -1 \|\| hi == -1` | **Falsified** — bytes use **`(lo & hi) == -1`** (both all-ones) |
| 4 | Same as `TFID_EqualsObjectId` (`00404aa0`) | **Weakened** — same 9-byte fields, **different** ABI (thiscall payload vs cdecl two TFID ptrs) and has pointer fallback |
| 5 | Scaffold `Named_CalleeOf_…RecvInvento…` product name | **Rejected** |
| 6 | `ret` bare / stdcall | **Falsified** — **`ret 4`** on all three exits |
| 7 | Many callers beyond track mgr | **Falsified** — only **2** CODE xrefs (`004bfd10`, `004bfdb0`) |
| 8 | Decompiler `bool __thiscall` wrong | **Survives** — AL/`setz`/`mov eax,1`/`xor eax,eax` + `ret 4` match |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual-mode CF | **High** | Wrong untrack / flag-set match |
| `ret 4` thiscall | **High** | Stack corruption |
| Invalid = both dwords -1 via AND | **High** | Miss identity fallback |
| Object TFID formula `+adj+0x164` | **High** (encoding) / **Med** (type name) | Wrong object identity |
| Product English | **None** | Registry pollution |
| Only two consumers | **High** (static xrefs) | Miss dynamic later |

---

## 3. Decompiler pitfalls (must survive port)

1. **Do not** drop the pointer-identity branch when porting “TFID equals”.  
2. **Do not** implement invalid as OR of -1 checks — must be **AND** then compare to -1.  
3. **Do not** call pure `TFID_EqualsObjectId` without adapting: this unit owns payload field offsets and object locate.  
4. Scaffold inventory/Recv chain name — **ignore**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Leaf match; 104 B; `ret 4`; bool | Product payload class name |
| Invalid→ptr / else TFID triple | That `*(object+4)` is a specific named vbase type |
| Used by 9-bucket track walkers | Additional undiscovered call sites without re-scan |
| Peer field set equals `TFID_EqualsObjectId` | Merging the two functions into one symbol |

---

## 5. CF challenge of Review A

- Dual-mode CF + ABI: **agree Confirmed**  
- Callers only untrack + flag-set: **agree**  
- Product gaps remain: **agree accept-with-gaps**  
- Naming `_Inferred` structural: **agree** (reject scaffold)

**Verdict:** **accept-with-gaps**
