# Review B (skeptical / adversarial): `aa_0040d4b0` HardpointList_FindById

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d4b0` |
| **VA** | `0x0040d4b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040d4b0_HardpointList_FindById.md` |
| **Evidence** | Full leaf bytes; parent CP assert dual; Respawn call sites |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Hash map / tree lookup | **Falsified** | Circular intrusive list walk |
| 2 | Returns payload object* directly | **Falsified** | Returns `node+8` (slot); callers deref |
| 3 | Mutates list / refcounts | **Falsified** | Pure loads |
| 4 | Logs on miss | **Falsified** | Silent null (assert parent logs) |
| 5 | Id at node+8 itself | **Falsified** | Id at `*(node+8)+8` |
| 6 | Free function no this | **Falsified** | thiscall registry + `ret 4` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Walk + match CF | **High** | Hardpoint attach fails |
| Return shape (node+8) | **High** | Double/single deref bug in port |
| Id English map | **Tentative** | Wrong hardpoint semantics |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
FindById(registry, id) -> nodePayloadSlot*|null
  walk circular list at *(*registry+0xC)
  match (*(node+8))->id@+8
  return node+8 or null
```

**Verdict:** **accept-with-gaps**
