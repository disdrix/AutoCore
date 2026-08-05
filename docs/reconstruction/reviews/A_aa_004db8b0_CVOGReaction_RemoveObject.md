# Review A (reconstruction fidelity): `aa_004db8b0` CVOGReaction_RemoveObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004db8b0` |
| **VA** | `0x004db8b0` |
| **Canonical name** | `CVOGReaction_RemoveObject` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004db8b0_CVOGReaction_RemoveObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **remove / destroy world object** by ids + remove mode:

1. Resolve via `CVOGReaction_ResolveObjectTarget(0, objectId, instanceId)`.
2. If miss: try `FUN_004e23d0`; clear bit4 at `+0x17d`; `FUN_004e2600(FUN_004cd4e0,…)`; return `0`.
3. If vtbl `+0x214` alive non-zero: if `this+0x7e` set call `FUN_004d0e90`; return `1` (already-live short path).
4. Type branch on clone type `obj[0x2a]+0x38`:
   - **1 or 3**: clear bit4 `+0x17d`, vtbl destroy `+0x144`, mode vtbl `+0x50(0|2)` from `bRemoveType`, notify `this+0xe500`, vehicle bits 5/6 cleanup via `+0x1c8/+0x1cc`.
   - **0x36**: special path with `FUN_004e2600` / vtbl `+0x1ec` / `FUN_004bc580`.
5. Common: vtbl `+0x2a8(this+0xe4e8)`, clear bit1 `+0x17d &= ~2`.
6. Insert into removal hash at `this+0xe5c0` (locked-traversal checks, node alloc `FUN_00589890`, link list).

Dispatched as reaction types **3 / 8** variants (Dispatch). Mirror of SpawnObject lifecycle.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004db8b0_CVOGReaction_RemoveObject.md` |
| Annotated | `docs/reconstruction/raw/aa_004db8b0_CVOGReaction_RemoveObject.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_RemoveObject.cpp` |
| Function record | `docs/reconstruction/functions/aa_004db8b0_CVOGReaction_RemoveObject.md` |
| Sibling | SpawnObject; ResolveObjectTarget |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(ctx*, objectId, instanceId, bRemoveType) → 0/1` | **High** | Raw |
| Resolve miss → 0 after soft cleanup | **High** | Explicit |
| Type 1/3 destroy arm | **High** | Clear branch |
| Type 0x36 special | **High** | Else-if |
| Removal hash at `+0xe5c0` | **High** | Insert tail |
| Spawn params `+0xe4e8` on unspawn vcall | **High** | Shared with Spawn |
| `bRemoveType` 0 vs nonzero → vtbl +0x50(0\|2) | **High** | Explicit |
| Type labels weapon/armor for 1/3 | **Probable** | Plate inference |
| Hash node full layout | **Tentative** | FUN_00589890 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Resolve miss path | **Yes** |
| Alive short path | **Yes** |
| Type arms + common unspawn | **Yes** |
| Hash insert + lock errors | **Yes** |
| Returns 0/1 | **Yes** |

---

## 5. Gaps

1. Dense vtbl map (destroy/unspawn/notify).
2. Full removal-hash consumers (when objects actually free).
3. Difference between reaction types 3 vs 8 (caller passes bRemoveType).
4. Server Delete reaction vs client apply.
5. Runtime remove capture open.

**Verdict:** Remove lifecycle CF preserved. **accept-with-gaps.**
