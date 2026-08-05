# Function record: FUN_009c3de0 / atexit_NetClassRep_rpcMsgGuaranteedOrdered

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c3de0` |
| **Canonical name** | `atexit_NetClassRep_rpcMsgGuaranteedOrdered` (**Inferred**) |
| **Ghidra name** | `FUN_009c3de0` |
| **Address** | `0x009c3de0` |
| **Body** | `0x009c3de0`–`0x009c3de9` (10 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | networking / TNL ClassRep CRT |
| **Calling convention** | atexit callback (no args); **tail-jumps** to `__thiscall` dtor with baked ECX |
| **Completion status** | **Sealed** — dual A/B W25-I 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (process-exit observe optional) |
| **Dual A/B** | **accept** (`reviews/A_aa_009c3de0_*`, `B_aa_009c3de0_*`) |
| **Last refined** | 2026-07-29 (W25-I OWN-ONLY dual) |

## Alias

| Name | Kind |
|---|---|
| `FUN_009c3de0` | Ghidra / scaffold |
| `atexit_NetClassRep_rpcMsgGuaranteedOrdered` | Inferred clean |

## Purpose

Compiler/CRT-generated **atexit destructor thunk** for the static
`TNL::NetClassRepInstance<RPC_TNLConnection_rpcMsgGuaranteedOrdered>` at
`DAT_00b04f40`. Loads ECX with the static object address and **jmp**s to
shared ClassRep dtor `FUN_005a2470` (free name string at `this[8]`, restore
base vtbl).

## Signature

```c
void atexit_NetClassRep_rpcMsgGuaranteedOrdered(void);
// body: mov ecx, 0x00b04f40; jmp FUN_005a2470
```

## Behavioral summary

1. `ECX = 0x00b04f40` (static ClassRep storage).
2. Tail-transfer to `FUN_005a2470` (does not return into this unit).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009c3de0_FUN_009c3de0.md`
- Annotated: `docs/reconstruction/raw/aa_009c3de0_FUN_009c3de0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/atexit_NetClassRep_rpcMsgGuaranteedOrdered.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_009c3de0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_009c3de0_atexit_NetClassRep_rpcMsgGuaranteedOrdered.md`
- Review B: `docs/reconstruction/reviews/B_aa_009c3de0_atexit_NetClassRep_rpcMsgGuaranteedOrdered.md`

## Callers / callees

| Direction | Target | Role |
|---|---|---|
| Callee (tail) | `FUN_005a2470` `0x005a2470` | ClassRep dtor |
| Xref (DATA) | CRT init @ `0x009c0ec5` | `atexit(this)` registration |

## Confidence

| Claim | Level |
|---|---|
| mov ecx + jmp bytes | **High** |
| this = `0x00b04f40` ClassRep for GuaranteedOrdered RPC | **High** (sibling seal + CRT name string) |
| atexit registration | **High** |
| Product atexit symbol English | **Inferred** |
