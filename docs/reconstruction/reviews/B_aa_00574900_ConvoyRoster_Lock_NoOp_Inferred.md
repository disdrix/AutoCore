# Review B (skeptical / adversarial): `aa_00574900` ConvoyRoster_Lock_NoOp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574900` |
| **VA** | `0x00574900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create**) |
| **Counterpart** | `reviews/A_aa_00574900_ConvoyRoster_Lock_NoOp_Inferred.md` |
| **Verdict** | **accept-with-gaps** — empty body + sole caller sealed; “lock” product word open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Real EnterCriticalSection / roster mutate | Invent lock body | **Falsified** — `c3` only |
| 2 | Multi-byte body / thunk | Pad misread as code | **Falsified** — function end = entry; pad is `cc` |
| 3 | `ret 4` twin of GetMember | ABI confuse with `00574760` | **Falsified** — opcode `c3` not `c2 04 00` |
| 4 | Same as Unlock `00574910` merge | Collapse pair | **Falsified** — distinct VAs; both empty but sandwich positions differ |
| 5 | Same as `00574e60` count | Cluster confuse | **Falsified** — count has real body + `ret 4` |
| 6 | Many callers / general API | Over-generalize | **Falsified** — **1** xref only |
| 7 | Required for correct XP math | Port must implement work | **Falsified for this image** — omittable no-op |
| 8 | Product name sealed as Lock | Over-promote | **Sustained** — placement heuristic only |
| 9 | Scaffold “~4 lines” implies logic | Auto CF noise | **Falsified** — empty return only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Machine `c3` | **High** | Invented lock side effects |
| Zero stack args | **High** | Wrong ABI |
| Sole OnDeathAward caller | **High** | Missed call sites |
| Call order before count/loop | **High** | Wrong port sequencing |
| “Lock” English | **Low / Tentative** | Misleading NAMING |
| Historical stripped CS | **Tentative** | Doc color only |

---

## 3. Cross-check

```text
// 0x00574900: c3
void ConvoyRoster_Lock_NoOp_Inferred(/* optional this ignored */)
{
  return;
}

// OnDeathAwardKillXp convoy arm (static order):
//   CALL 00574900   // this
//   CALL 00574e60   // count eligible
//   loop CALL 00574760 + award
//   CALL 00574910   // unlock twin
```

---

## 4. Surviving contract for AutoCore

```
ConvoyRoster_Lock_NoOp_Inferred():
  // retail: RET only
  // Port: omit entirely OR keep empty stub for call-graph parity
  // Do NOT invent CS enter / roster writes
```

**Port tests:** Removing CALL must not change XP awards in this image; do not merge into count or GetMember.

---

## 5. Open questions

1. PDB / original name (Lock vs Begin vs empty stub).
2. Whether any **data**/vtbl xref exists beyond the one CALL (this pass: code CALL only).
3. Runtime ordering sensitivity if a future build fills the body.

**Verdict:** **accept-with-gaps** — hidden-body and multi-caller attacks **closed**; product “lock” label remains inferred.
