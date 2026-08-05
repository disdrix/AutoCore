# Review B (skeptical / adversarial): `aa_004f1ff0` Object_CollectAllGraphicsPreloads

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1ff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-H) |
| **Counterpart** | `reviews/A_aa_004f1ff0_Object_CollectAllGraphicsPreloads.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Scaffold `Named_CalleeOf_*` chain is product name | **Rejected** — plate `"CollectAllGraphicsPreloads"` wins |
| 2 | cdecl / no stack cleanup | **Falsified** — `C2 04 00`; entry `MOV EBP,ECX` |
| 3 | Always loads all tread/fork assets | **Falsified** — gated by type `0x0e` + clone kind 2/4 |
| 4 | `param_2` unused | **Falsified** — forwarded to `FUN_004a04f0` when `this+0x88≠0` |
| 5 | `FUN_004eb010` runs for all types | **Falsified** — only after successful type-0x0e clone path |
| 6 | Existence check optional | **Falsified** — both `007b6a20` and `007b6730` required before enqueue |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX object + RET 0x4 | **High** | Wrong host / stack |
| Plate name | **High** | Naming only if wrong |
| Suffix constants | **High** | Wrong asset paths |
| Type/kind gates | **High** | Over/under-preload |
| Nested residual collectors | **Open** | Missing sibling preloads |
| Product type English | **Low** | Docs only |
| Runtime | **Open** | FS / pack order |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  timer begin
  optional tint / tur
  if type==0x0e: lookup clone; kind 2|4 suffix packs; 004eb010
  004eb3b0; maybe 004a04f0(param_2,1,0,0); timer end

bytes:
  8B E9          ; MOV EBP, ECX
  … C2 04 00     ; RET 4
  strings: _tint.dds _tur.geo _frk{t,b}.geo _trd{left,right}{,.geo,_ai.anm}
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Peer `004b88e0` not inlined — reached only via `004a04f0`.

---

## 4. Surviving contract for AutoCore

```
// Object_CollectAllGraphicsPreloads:
//   ECX = object; stack = param_2; RET 0x4; void
//   stem = this+0x188; type = this+0x38; clonebase = *(this+0x3c)
//   exists-gate before enqueue; suffixes sealed
//   type 0x0e only for fork/tread pack + 004eb010
//   always 004eb3b0; if this+0x88: 004a04f0(param_2,1,0,0)
// Do not use scaffold Named_CalleeOf_* name.
// Do not skip existence gate or type/kind filters.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/plate/suffixes/gates; nested residual product open → **accept-with-gaps**.
