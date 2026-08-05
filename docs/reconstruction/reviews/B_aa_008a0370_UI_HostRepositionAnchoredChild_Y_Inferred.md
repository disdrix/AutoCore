# Review B (skeptical / adversarial): `aa_008a0370` UI_HostRepositionAnchoredChild_Y_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008a0370_UI_HostRepositionAnchoredChild_Y_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Creates/destroys children | **Falsified** — only vfunc get/set position |
| 2 | Always uses centered formula | **Falsified** — branch on +0x520/+0x664 |
| 3 | Moves multiple children | **Falsified** — only +0x684 target |
| 4 | Pure thiscall ECX | **Falsified** — `in_EAX` host |
| 5 | Bit-exact pad constants without read_memory | **Weak** — sealed via `read_memory` floats |

## Surviving contract

```text
// After CharSheet CreateChildWidgets / refresh chrome:
//   EAX = host with child slots wired
UI_HostRepositionAnchoredChild_Y();
// child@+0x684 Y updated; X preserved from get-pos
```

**Gaps kept:** product English of +0x624/+0x664 widgets; full vec2 layout of vfuncs.

**Verdict:** **accept-with-gaps.** Accept A.
