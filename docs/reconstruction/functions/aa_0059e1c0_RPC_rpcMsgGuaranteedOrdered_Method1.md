# Function record: RPC_rpcMsgGuaranteedOrdered_Method1

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059e1c0` |
| **Canonical name** | `RPC_rpcMsgGuaranteedOrdered_Method1` |
| **Proposed semantic name** | `RPC_TNLConnection_rpcMsgGuaranteedOrdered_getClassRep` |
| **Address** | `0x0059e1c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `networking` (TNL RPC / NetClassRep) |
| **Completion status** | **Human-refined stub** — three-rep + dual A/B sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Virtual **getClassRep** for TNL event class `RPC_TNLConnection_rpcMsgGuaranteedOrdered`.
Returns the address of the static `NetClassRepInstance` at `DAT_00b04f40` (constructed
at CRT init with class name string `RPC_TNLConnection_rpcMsgGuaranteedOrdered`,
NetClassTypeEvent=2, group=1, version=0).

No pack, unpack, or execute logic.

## Signature (sealed)

```c
// Ghidra: undefined * RPC_rpcMsgGuaranteedOrdered_Method1(void)
// Semantic:
TNL::NetClassRep* __thiscall
RPC_TNLConnection_rpcMsgGuaranteedOrdered_getClassRep(
    RPC_TNLConnection_rpcMsgGuaranteedOrdered* /* this, unused */);
// Body: return &DAT_00b04f40;
```

## Body

```text
0059e1c0  B8 40 4F B0 00    mov eax, 0x00b04f40
0059e1c5  C3                ret
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.md` |
| Annotated | `docs/reconstruction/raw/aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RPC_rpcMsgGuaranteedOrdered_Method1.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.md` |

## Callers / callees

| Direction | Detail |
|---|---|
| **Callees** | none |
| **Callers (direct CALL)** | none |
| **DATA xref** | vtbl `PTR_RPC_rpcMsgGuaranteedOrdered_Method1_009d7c8c` @ `0x009d7c8c` slot 0 |
| **Vtbl installers** | `FUN_0059ea60`, `FUN_0059eb40`, `FUN_0059ec00`, `FUN_005a2b10` |
| **ClassRep storage** | `DAT_00b04f40` (size `0x38`); CRT init `0x009c0eb0` → `FUN_005a2410` |
| **Related (not owned)** | Execute `aa_005a2a50`; dtor `FUN_005a2970`; pack/unpack `FUN_00780810`/`00780800` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler / memory | **High** |
| Return target absolute address | **High** |
| ClassRep / product class identity | **High** |
| Semantic name getClassRep | **High** |
| Parameter semantic names | N/A (this unused) |
| Runtime class-id samples | **Open** |
