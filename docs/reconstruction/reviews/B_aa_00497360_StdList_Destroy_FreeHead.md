# Review B (skeptical / adversarial): `aa_00497360` StdList_Destroy_FreeHead

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-K) |
| **Counterpart** | `reviews/A_aa_00497360_StdList_Destroy_FreeHead.md` |
| **Scratch** | `tmp/a_00497360.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Trust raw decompile as authoritative CF | **Falsified** — decompile shows one conditional delete + noreturn ladder; bytes show free-loop + fall-through |
| 2 | This is clear-only (keeps sentinel) | **Falsified** — second `operator_delete([list+4])` + `list+4=0` |
| 3 | thiscall with stack args | **Falsified** — only ECX; bare `RET` |
| 4 | Deletes payload fields with dtors | **Falsified** — nodes freed as blocks via `operator_delete` only; no vtbl call |
| 5 | Ghidra body end `0x0049739b` | **Falsified** as complete range — ends mid-CALL; full end `0x004973a7` |
| 6 | Identical to `0x00403430` | **Related but not identical** — 00403430 calls clear helper; this inlines loop and nulls head |
| 7 | Product name is retail symbol | **Overstated** — structural MSVC list; name is role-based |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-loop + sentinel free + null | **High** | Leak / use-after-free on port |
| ECX list ABI | **High** | Wrong object destroyed |
| No element dtor calls | **High** | Wrong ownership model |
| MSVC list product English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
LEA ECX, [ESI + listOffset]   ; CVOGSectorMap embedded lists
CALL 00497360                 ; void
```

Sample: `0x004d687c` `LEA ECX,[ESI+0xe8e4]`; `0x004d6887` `LEA ECX,[ESI+0xe8d8]`. Pattern matches list-member teardown after other free helpers.

---

## 4. Surviving contract for AutoCore

```
// Port:
StdList_Destroy_FreeHead(list);
// after: list+4 == null, list+8 == 0, all nodes + former sentinel freed
// do NOT call element destructors here — only operator_delete on nodes
// safe on already-empty list (first == head → skip loop)
```

---

## 5. Verdict

Adversarial pass **confirms** A and **rejects** scaffold decompile as sole CF source → **accept** on byte-sealed destroy contract.
