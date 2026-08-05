# Review B (skeptical / adversarial): `aa_0044fee0` NestedHash0x10_StaticOnceGet_d1fcc0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-E) |
| **Counterpart** | `reviews/A_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall method | **Falsified** — no ECX load; no stack formals; plain RET |
| 2 | Returns NestedHash object by value / ctor EAX | **Falsified** — always `MOV EAX,&DAT_00d1fcc0` after optional ctor |
| 3 | Re-inits every call | **Falsified** — once-flag bit0 on `DAT_00d1fce8` |
| 4 | anmTrackEvents product name (scaffold) | **Falsified** — sole caller is `FUN_0044fe10` bag path; no string in body; reject scaffold name |
| 5 | Different NestedHash node size | **Falsified** — callee is sealed W34-E **0x10** sentinel ctor |
| 6 | Heap singleton | **Falsified** — static BSS object `DAT_00d1fcc0` |
| 7 | Thread-safe once (std::call_once) | **Careful** — plain bit flag; no CS; pattern matches other statics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Once-get ABI | **High** | Wrong convention |
| Flag + static addresses | **High** | Wrong global |
| Ctor identity | **High** | Wrong layout |
| Sole caller function | **High** | Over-claim product |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 90 B hex ends `83c40c c3` (frame tear + RET).
- Call sites only from `FUN_0044fe10` (2×).
- DATA: `DAT_00d1fcc0` also referenced by atexit thunk `009c34b0`.
- Family: byte-level pattern matches `FUN_00438c40` / `FUN_00438ca0` with different static/flag/atexit labels.

---

## 4. Surviving contract for AutoCore

```
// Port as process-static once-get (not a method):
NestedHash10* GetStaticNestedHash_d1fcc0() {
  static bool once; // or bit0 of shared flags dword
  if (!once) {
    once = true;
    NestedHash0x10_Ctor(&g_static);  // placement
    atexit(DtorThunk);
  }
  return &g_static;
}
// Do not re-construct each call. Do not hard-wire anmTrackEvents.
// Pair with NestedHash_Ctor_Sentinel0x10 (W34-E).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/flag/ctor/return/xrefs. Scaffold product name rejected. Residual product plate does not reopen sealed contract → **accept**.
