# Review B (skeptical / adversarial): `aa_00989270` GfxAttachmentList_FindByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00989270_GfxAttachmentList_FindByKey.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function equips ornament | **Falsified** — lookup only; parent writes slot |
| 2 | Linear null-terminated list | **Falsified** — stop when node == head |
| 3 | Key compared at node+8 | **Falsified** — key at `*(node[2]+8)` |
| 4 | Always returns non-null | **Falsified** — full walk → 0 |
| 5 | Key 100 product English | **Fail** — immediate only |

---

## 2. Surviving contract

```
thiscall(listOwner, key) -> payload*|null
  circular walk head at owner+0xc
  match *(node.payload + 8) == key
```

Ornament dual call with key 100 **survives**.

---

## 3. Open

Key dictionary; owner type name.

**Verdict:** Lookup CF sealed. **accept-with-gaps.**
