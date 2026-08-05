# Review B (skeptical / adversarial): `aa_008aa320` NpcMissionDialog_TeardownChildWidgetLists

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa320` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-T) |
| **Counterpart** | `reviews/A_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX-thiscall on dialog | Body never takes ECX as this; all fields via **ESI**; sole caller does not set ECX before CALL | **Falsified** |
| 2 | Clears prepared response `+0x650` | No store near `0x650` / dword `0x194`; Flush already handled send | **Falsified** |
| 3 | Clears / shrinks the two vectors after walk | No write to begin/end; no `operator_delete` on storage | **Falsified** as vector free |
| 4 | Sends 0x206E / any sector packet | Pure virtual calls; no net connection | **Falsified** |
| 5 | Single list only | Two full loops with distinct offsets +0x72c and +0x73c | **Falsified** |
| 6 | Order is remove-then-destroy | Live: **child 0x440 first**, then dialog 0xb0 | **Falsified** if reversed |
| 7 | Multi-caller utility | Exactly **1** xref — FlushPreparedResponse | **Overstated** if claimed general |
| 8 | `ret 4` / stack args | Bare `c3`; no stack args | **Falsified** |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI dialog ABI; bare ret | **High** | Wrong calling convention |
| Two vector pairs + count math | **High** | Miss half of children |
| Virtual order 0x440 → 0xb0 | **High** | UAF / double-remove |
| Flush-path only | **High** | — |
| Product list English | **Low–Med** | Naming only |
| Exact product meaning of vtbl+0xb0 | **Med** | structural remove sealed; English open |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `8b 86 2c 07…`, ends `…5f 5d 5b c3` |
| Caller site ESI live | **Yes** — after CALL: `mov edx,[esi]; mov ecx,esi; call [edx+0x3ac]` |
| Flush plate positions this after wire/reward | **Yes** sealed parent clean |
| No +0x650 in body | **Yes** decompile + hex scan |

**Attack on “this is the wire flush”:** **Fails** — wire is parent; this is child teardown only.

**Attack on “ECX thiscall member that clears +0x650”:** **Fails** — ESI ABI; no packet field touch.

---

## 4. Surviving contract for AutoCore

```
// ESI = NpcMissionDialog*
// bare ret; saves EBX/EBP/EDI
// for each non-null in vec(+0x72c/+0x730) and vec(+0x73c/+0x740):
//   child->vtbl+0x440();
//   dialog->vtbl+0xb0(child);
// does NOT free vectors, clear +0x650, or call vtbl+0x3ac
```

**Falsified port mistakes:**

- Calling as ECX-thiscall without ESI.
- Clearing `+0x650` here (belongs to construct/build / separate paths — see Flush dual).
- Freeing vector storage or assuming begin/end zeroed.
- Reversing virtual order (remove before child close).
- Treating this as the 0x206E send site.

---

## 5. Open questions

1. Product English for the two child lists (reward widgets vs option rows, etc.).
2. Product names for dialog `vtbl+0xb0` and child `vtbl+0x440`.
3. Whether any other path should call this (only Flush does today).
4. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/offsets; reject ECX / wire / vector-free / reverse-order myths.
