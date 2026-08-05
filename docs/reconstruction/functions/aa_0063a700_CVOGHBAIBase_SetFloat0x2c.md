# Function record: CVOGHBAIBase_SetFloat0x2c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063a700` |
| **Canonical name** | `CVOGHBAIBase_SetFloat0x2c` |
| **Address** | `0x0063a700` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | hbai |
| **Completion status** | **Dual A/B sealed** 2026-07-29 (W19-P) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Role |
|------|------|
| `FUN_0063a700` | Ghidra / scaffold |
| `Named_CalleeOf_CVOGHBAIBase_Default_ctor_0063a700` | legacy auto alias |

## Purpose

Leaf **float field setter**: writes `value` to HBAI object offset **`+0x2c`** via SSE `movss`. Used by Turreted / Default HBAI constructors with **0.0f**, and exposed as **vtbl[+0x20]**.

## Signature (sealed)

```c
void __thiscall CVOGHBAIBase_SetFloat0x2c(void *this /*ECX*/, float value /*stack*/);
// ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0063a700_FUN_0063a700.md` (+ 2026-07-29 live)
- Annotated: `docs/reconstruction/raw/aa_0063a700_FUN_0063a700.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBAIBase_SetFloat0x2c.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0063a700.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md`
- Review B: `docs/reconstruction/reviews/B_aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md`

## Callers / callees

| Direction | Target | Notes |
|-----------|--------|-------|
| Caller | `CVOGHBAIWalkingCreatureTurreted_ctor` @ `0x00639860` | `push 0` |
| Caller | `CVOGHBAIBase_Default_ctor` @ `0x0063c966` | `push 0` |
| DATA | vtbls @ `0x009e3ce0`, `0x009e3d60`, `0x009daaf0`, `0x009dab70`, `0x009dabf0` | method pointer |
| Callees | none | leaf |

## Confidence

| Claim | Level |
|---|---|
| Control flow / single store | **High / Sealed** |
| Float SSE store at `+0x2c` | **High / Sealed** (bytes) |
| ABI `__thiscall` + `ret 4` | **High / Sealed** |
| Product name of `+0x2c` field | **Open** |
| Canonical name product accuracy | **Probable** (role-based; PDB unknown) |
