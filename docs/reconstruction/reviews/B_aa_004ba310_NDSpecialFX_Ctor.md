# Review B (skeptical / adversarial): `aa_004ba310` NDSpecialFX_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ba310_NDSpecialFX_Ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is a copy/clone of template | Clone is `0x004a0b90`; this only defaults + name | **Falsified** merge |
| 2 | Is XML parser | Parser is `0x004a4fa0`; this is leaf ctor | **Falsified** merge |
| 3 | `__stdcall` / no this | `MOV ESI,ECX`; `RET 4` only pops name | **Falsified** |
| 4 | Size unknown / not 0x240 | Both callers `operator_new(0x240)` | **Survives** 0x240 |
| 5 | Name at different offset | `LEA EDX,[ESI+0xd5]` + `strncpy` cap `0x104` | **Survives** +0xd5 |
| 6 | Sets event type | ctor leaves +0x28 zero; ParseXml writes after | **Falsified** "full init" |
| 7 | Prior VOG_DEBUG_STOP name | string is assert in *callers*, not this body | **Falsified** scaffold alias |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23 body. Callers list matches `get_function_callers` (2). Callees: `FUN_004933f0`, `FUN_0074ba00`, `strncpy`, `FUN_00439770`. Epilogue `C2 04 00` sealed via `read_memory`.

---

## 3. Surviving contract

```
// ECX = NDSpecialFX* (0x240)
// name @ [esp+4]
// defaults + nested ctor + 6 empty lists + tree + tick + strncpy(+0xd5,name,0x104)
// EAX = this; RET 4
```

**Gaps kept:** nested product names; full layout; DAT_009cb2a0 exact type.

**Verdict:** **accept-with-gaps**.
