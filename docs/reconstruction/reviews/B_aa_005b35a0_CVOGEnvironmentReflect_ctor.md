# Review B (skeptical / adversarial): `aa_005b35a0` CVOGEnvironmentReflect_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b35a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W32-T) |
| **Counterpart** | `reviews/A_aa_005b35a0_CVOGEnvironmentReflect_ctor.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is Distort / Water singleton ctor | **Falsified** — size **0x170** not 0x18/0x20; always constructed; parent@`+0xB8` not view@`+0xC0` |
| 2 | Class unknown / only adjacent RTTI string | **Falsified** — COL@vtbl[-1] → **`.?AVCVOGEnvironmentReflect@@`** at type_info `0x00af3eb0` |
| 3 | `FUN_0044b440()` takes no args (decompiler) | **Falsified** — bytes push **1.0 / -1.0 / 1.0** via `movss` before call; ECX=`this+0x90` |
| 4 | Returns void / not this | **Falsified** — `mov eax,esi` before epilogue; factory stores result @ env`+0xC4` |
| 5 | Process singleton like Distort | **Falsified** — no global gate; new every InitPhases call into owned slot |
| 6 | Same object as Palantir env host (0x198) | **Falsified** — different vtbl (`009d95a0` vs `009c7928`); size 0x170; nested under env`+0xC4` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class = CVOGEnvironmentReflect | **Confirmed** | Wrong fog/reflect host type |
| Owned 0x170 under env+0xC4 | **Confirmed** | Leak / wrong parent lifetime |
| Enable flags +0x78/+0x80 default 1 | **Confirmed** | Apply path gates on +0x80 |
| Matrix sub @ +0x90 | **Confirmed** | Transform init skipped |
| Nested helper product names | **Open** | Port comments only |

---

## 3. Cross-check

```
raw: FUN_007560d0; vtbl 009d95a0; FUN_00972cc0; parent wires; FUN_0044b440; optional 00972e50; flags 1
live: identical CF
bytes: SEH 009a67ed; call 007560d0; c706 a0959d00; lea edi,[esi+90h]; movss 1.0/-1.0; call 0044b440; test [esi+14Ch]; set +78/+80; ret 4
factory 0048fc90: new(0x170); FUN_005b35a0(parent@+B8); env+C4=result; FUN_005b39a0(1)
apply peer 005b36f0: vtbl[1]; uses +15c/+164/+80/+78/+158
RTTI: COL 00aafff8 → 00af3eb0 ".?AVCVOGEnvironmentReflect@@"
```

---

## 4. Surviving contract for AutoCore

```
CVOGEnvironmentReflect_ctor(this, parent):
  PhaseBase_like_ctor(this)          // FUN_007560d0
  this.vtbl = CVOGEnvironmentReflect_vtbl
  MatrixDefault(this+0x90)           // FUN_00972cc0
  this.parent = parent               // +0x15C
  this.slot160 = parent->field_E4E8
  this.slot164 = parent->field_E894
  MatrixStamp(this+0x90, 1, -1, 1)
  optional MatrixPost if flag@+0x14C
  this.enable78 = this.work80 = 1
  return this
```

Port as **owned env child** (always new on InitPhases), not process singleton. Follow with enable(1). Apply fog+reflect via vtbl[1] residual already dualed (W29-I).

---

## 5. Open questions

1. Product names for base/matrix helpers (non-blocking for ctor shape).
2. Runtime golden for parent nested field types.

**Verdict:** **accept-with-gaps**
