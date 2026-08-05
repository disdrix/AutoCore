# Review A (reconstruction fidelity): `aa_0057a190` CVOGReaction_ShowDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057a190` |
| **VA** | `0x0057a190` |
| **Canonical name** | `CVOGReaction_ShowDialog` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0057a190_CVOGReaction_ShowDialog.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Copy **dialog presentation fields** from a source object into a dialog/reaction sink, then resolve empty text slots via map variables:

1. If `param_2 == 0` → no-op.
2. Copy four dwords from `src+0x160..+0x16c` → `dst+0x30..+0x3c`.
3. Iterate pointer range `[dst+0xc, dst+0x10)`; for each entry whose first byte is 0, call `CVOGMap_LookupVariable(id, outBuf, src)`.

Prepares dialog strings/params; does not itself open the full mission UI shell.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0057a190_CVOGReaction_ShowDialog.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_ShowDialog.cpp` |
| System map | `docs/reconstruction/systems/missions-progression.md` (when present) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(dst, src)` | **High** | Raw |
| Null src no-op | **High** | Guard |
| Copy 0x160.. range → +0x30 | **High** | Four stores |
| Variable fill for empty slots | **High** | Loop + LookupVariable |
| Field meanings (title/body/buttons) | **Tentative** | Unlabeled dwords |
| Opens fullscreen dialog UI | **Low** | Not shown in body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null guard | **Yes** |
| Four dword copies | **Yes** |
| Empty-slot variable loop | **Yes** |
| No extra UI open call | **Yes** |

---

## 5. Gaps

1. Semantic labels for +0x30..+0x3c and +0x160..+0x16c.
2. Whether a caller opens the widget after this.
3. Variable table schema.
4. Runtime mission dialog.

**Verdict:** accept-with-gaps.
