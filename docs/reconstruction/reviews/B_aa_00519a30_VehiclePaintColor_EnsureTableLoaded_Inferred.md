# Review B (skeptical / adversarial): `aa_00519a30` VehiclePaintColor_EnsureTableLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519a30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — W16-D) |
| **Counterpart** | `reviews/A_aa_00519a30_VehiclePaintColor_EnsureTableLoaded_Inferred.md` |
| **System** | vehicle paint / tint |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `MedalDef_EnsureTableLoaded` (`00519660`) | Different globals (`b042ac` vs `b042e0`); vColor* not medals | **Falsified** medal identity |
| 2 | Pure getter / no mutation | Recreates hash, inserts nodes, frees vectors | **Falsified** getter |
| 3 | Returns paint handle | `void`; side effect on globals only | **Falsified** return-value |
| 4 | Loads a single table | Three vectors + three merge phases | **Falsified** single-table |
| 5 | Always replaces RGB on phase 2/3 hit | Hit path only writes `+8` / `+0xC`, not `+0` | **Survives** — first insert owns RGB |
| 6 | `ExceptionList = local_20` is real | `local_20` zeroed as vector field; epilogue uses SEH slot | **Falsified** decompiler bind |
| 7 | `operator_delete` never returns | SEH/decompiler artifact; cleanup continues | **Falsified** as product noreturn |
| 8 | Scaffold Client_InitInstance-only | Also Lookup + paint setters + UI xrefs | **Falsified** sole-caller |
| 9 | Payload fully initialized | `operator_new(0x10)` no zero; partial inserts | **Survives** as gap |
| 10 | Product name sealed | No plate on this VA | **Survives** `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lazy ensure for Lookup when count `< 1` | **Confirmed** | Missing table → null paints |
| Hash recreate power 4 @ `b042ac` | **Confirmed** | Wrong bucket count |
| vColor* / IDColor/RGB/Worth domain | **High** | Wrong asset table |
| Three-phase insert/update | **Confirmed** | Incomplete merge |
| Phase↔faction assignment | **Tentative** | Mis-label worth slots only |
| Secondary map `0051d430` | **Tentative** | Ordered enumeration residual |
| Uninit payload holes | **High** | Only if readers use +4/+8/+0xC blindly |
| Runtime DB availability | **Open** | Empty table if DB fail |

---

## 3. Live ≡ raw

```
Live ≡ raw CF:
  SEH → Recreate(hash,4) → zero vecs
  → DB enter → 007c9230 → DB leave
  → phase1 always insert (RGB,+4)
  → phase2 lookup merge (+8)
  → phase3 lookup merge (+0xC)
  → free vecs → return

Sibling Lookup dual:
  ensure → bucket → key@+0x10 → *value@+8 → *payload(+0)
```

Loader plate (`007c9230`) supplies English domain without needing this VA’s strings.

---

## 4. Surviving contract for AutoCore

```
// Client global paint-color table (lazy)
void VehiclePaintColor_EnsureTableLoaded(void);
// Side effects:
//   DAT_00b042ac hash rebuilt (mask DAT_00b042b4, buckets DAT_00b042bc)
//   DAT_00b042b8 count becomes #inserted keys
//   Each key IDColor → payload{ rgb@+0, worth_a@+4, worth_b@+8, worth_c@+0xC }

// Lookup (sibling):
//   if (count < 1) Ensure();
//   return payload ? payload->rgb : 0;

// AutoCore:
//  - Server may own authoritative paint ids; client table is presentation (RGB/worth).
//  - Port Ensure once at garage/tint init OR on first Lookup.
//  - Do not assume payload[+4,+8,+0xC] valid unless all three faction rows exist for id.
```

Pair with:

- `VehiclePaintColor_LookupById_Inferred` `0x00519d20`
- Paint setters `004faaf0` / `004fab40` (vehicle `+0x1a8` / peer)
- Tint refresh `004fcd80` (`_tint.dds`)
- DB bookends `007e1d80` / `007b7df0`
- Loader `007c9230` (vColor* plate)

---

## 5. Open questions (residual only)

1. Pin phase order → Biomek/Human/Mutant via stack args into `007c9230`.
2. Name/role of `FUN_0051d430` secondary map (id ordering for clamp UI?).
3. DB failure path (empty vectors → count stays 0 → Lookup loops ensure?).
4. Runtime verification against live `vColor*` row counts.

**Verdict:** **accept-with-gaps**. CF and paint-domain contract sealed for AutoCore; faction-phase labels and secondary map remain non-blocking residuals.
