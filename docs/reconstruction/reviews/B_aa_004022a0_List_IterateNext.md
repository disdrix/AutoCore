# Review B (skeptical / adversarial): `aa_004022a0` List_IterateNext

| Field | Value |
|---|---|
| **Stable ID** | `aa_004022a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004022a0_List_IterateNext.md` |
| **Verdict** | **accept-with-gaps** on CF + return codes; product type / TryEnter policy open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is TraversalLock itself | No Enter/set `+0x28`; only TryEnter + walk | **Falsified** — sibling `0x004294f0` |
| 2 | Unlocked list still iterates | `+0x28==0` → `0x80070005` | **Falsified** |
| 3 | Return 0 = error | 0 = have node; 1 = done; HRESULT-like only on lock fail | **Falsified** |
| 4 | Mutates list membership | Only cursor/payload outs + LeaveCS | **Falsified** |
| 5 | Payload at `node+0` | Load is `*(node+4)` | **Falsified as +0** |
| 6 | Next at `node+4` | Next is `*(node+8)` | **Falsified** |
| 7 | Inventory-only helper | Hundreds of xrefs across systems | **Survives as shared leaf** — inventory is primary consumer family |
| 8 | Clean is bit-exact | Scaffold only | **Gap** — CF sealed, bit-exact open |

---

## 2. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Cursor/next/payload CF | **High** | Broken cargo scans |
| Lock gate + TryEnter | **High** | Spurious empty results |
| Return code trichotomy | **High** | Loop off-by-one |
| Pairing with TraversalLock | **High** | Deadlock/missed unlock at callers |
| Product list class name | **Open** | Doc only |
| Runtime | **Open** | Edge races |

---

## 3. Cross-check

Live decompile ≡ frozen raw (2026-07-23). Prologue bytes confirm SEH + `this` in ECX (`mov esi,ecx` family after frame). Inventory duals for `0x00571010` / `0x005711c0` already treat this as **List_IterateNext**.

---

## 4. Surviving contract

```
// Requires prior List_TraversalLock (list+0x28 == 1)
uint List_IterateNext(List* list, Node** cursor, void** outPayload);
// 0 = *outPayload valid; 1 = end; 0x80070005 = not locked / TryEnter fail
```

---

## 5. Open

1. TryEnter failure frequency / intentional design.
2. Node allocator / free list ownership.
3. Runtime multi-thread stress.

**Verdict:** CF + inventory consumer role **survive**. **accept-with-gaps.**
