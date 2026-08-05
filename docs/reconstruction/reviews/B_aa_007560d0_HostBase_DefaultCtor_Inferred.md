# Review B (skeptical / adversarial): `aa_007560d0` HostBase_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007560d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-O) |
| **Counterpart** | `reviews/A_aa_007560d0_HostBase_DefaultCtor_Inferred.md` |
| **Scratch** | `tmp/a_007560d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP` is product | **Rejected** — parent-seed alias; 6 diverse callers |
| 2 | Complete most-derived ctor (final vtbl) | **Falsified** — callers overwrite vtbl (e.g. PalantirEnv `009c7928`) |
| 3 | Object size exactly 0x7C | **Nuanced** — written through `+0x78` (≥0x79); peer alloc **0x80** |
| 4 | `FUN_0076c500` runs on `this` not `this+0x10` | **Falsified** — `8D 7E 10` + `8B CF` |
| 5 | Hard-kill float is 1.0f | **Falsified** — `g_flHardKillInterpolate` = **0.005f**; ones are `DAT_00afdf40` float4 |
| 6 | Has stack formals | **Falsified** — plain RET; ECX only |
| 7 | Product name `HostBase_DefaultCtor` retail | **Overstated** — **Inferred** structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + return this | **High** | Wrong object |
| Full field map / constants | **High** | Wrong defaults |
| Subobject @ +0x10 | **High** | Wrong this-adjust |
| Final vtbl permanence | **High** (overwritten) | Stale vtbl assumption |
| Product class English | **Inferred** | Naming only |
| Nested helper roles | **Open** | Subobject mis-model |

---

## 3. Cross-check against raw + bytes

```
body 007560d0..0075617e C3 / pad CC → 175 B
C7 06 34 F5 A9 00          ; vtbl PTR_FUN_00a9f534
8D 7E 10 68 E8 03 00 00    ; LEA this+0x10; PUSH 1000
F3 0F 10 05 A4 A6 AA 00    ; movss g_flHardKillInterpolate
C6 46 78 01                ; byte +0x78 = 1
8B C6 … 83 C4 10 C3        ; return this; SEH teardown; RET

DAT_00afdf40: 3F800000 ×4
00aaa6a4: 3BA3D70A = 0.005f
callers include PalantirEnv, UI new(0x80), phase ctors
```

Live ≡ raw. Adversarial residual is product demangle + nested callees only.

---

## 4. Surviving contract for AutoCore

```
// HostBase default ctor (first stage):
//   ECX = self*; returns self; no stack args; plain RET
//   vtbl = PTR_FUN_00a9f534 (often replaced by derived)
//   subobject this+0x10: FUN_0076c500(1000) then FUN_0076c4d0
//   +0x40/+0x44 = 1000; float4 ones @ +0x60; hardkill 0.005f @ +0x74; flag +0x78=1
//   written span ≥ 0x79; do not assume final product class from this vtbl alone
//   reject VOG_DEBUG_STOP parent-seed name
```

---

## 5. Verdict

Adversarial pass confirms A; product/nested residual only → **accept-with-gaps**.
