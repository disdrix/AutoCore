# Review B (skeptical / adversarial): `aa_0074e380` HostAux40_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e380` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-R) |
| **Counterpart** | `reviews/A_aa_0074e380_HostAux40_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall on self | **Falsified** — `8B 74 24 14` loads self from stack; no `8B F1`; `C2 04 00` |
| 2 | Zeroes entire 0x40 | **Falsified** — `+0x04` never written; NestedHash owns `+0x14…+0x3b` |
| 3 | Writes float at `+4` / index 1 | **Falsified** — decompiler `param_1[2..4]` are dword offsets `+8/+c/+10`; `param_1[0xf]` = `+0x3c` |
| 4 | Multiple direct callers | **Falsified** — single xref from `PoolHost_Acquire0x40` freelist-miss path |
| 5 | Product class fully named | **Overstated** — `_Inferred` structural from HostAux14 peer + PoolHost 0x40 + HostBase `+4` |
| 6 | Scaffold VOG_DEBUG chain is product | **Reject** — auto parent-seed alias, not demangle |
| 7 | Same object as HostAux14 | **Falsified** — different size (0x40 vs 0x14), different slot (`+4` vs `+8`), NestedHash embed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor / return self | **High** | Mis-owned port |
| ABI stack-self / RET 4 | **High** | Stack imbalance |
| NestedHash @ `+0x14` | **High** | Layout corruption |
| Size 0x40 / pool wiring | **High** | Wrong freelist element |
| Float head semantics | **Low** | Naming / domain only |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against pool + HostBase

```
// PoolHost_Acquire0x40 @ 0x00986070 (W33-R):
//   if freelist empty: operator_new(0x40); FUN_0074e380(raw)
//   always track-push; return obj*
// HostBase_EnsureAuxPtrs @ 0x00756320 (W32-Q):
//   if (flags & 1): host+4 = Acquire0x40(*DAT_00d1f624)
// NestedHash_Ctor_Sentinel0xC @ 0x0043fdf0 (W34-F):
//   caller FUN_0074e380 @ 0x0074e3ba with param_1+5 (= +0x14)
```

Confirms this VA is **0x40 element ctor only**; freelist pop path skips it.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (stack this, RET 4):
obj = HostAux40_Ctor(raw_0x40);
// Must: float1.0 @+0; zero +8/+c/+10/+3c; NestedHash0xC @+0x14
// Must NOT: write +4; treat as thiscall; invent product plate
// Keep NestedHash / PoolHost / HostBase as separate units
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, layout, NestedHash embed, and sole pool path. Product English residual → **accept-with-gaps**.
