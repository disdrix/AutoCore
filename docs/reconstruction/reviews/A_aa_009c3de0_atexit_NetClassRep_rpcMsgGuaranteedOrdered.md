# Review A (reconstruction fidelity): `aa_009c3de0` atexit_NetClassRep_rpcMsgGuaranteedOrdered

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c3de0` |
| **VA** | `0x009c3de0` |
| **Body** | `0x009c3de0`–`0x009c3de9` (10 bytes) |
| **Canonical name** | `atexit_NetClassRep_rpcMsgGuaranteedOrdered` (Ghidra `FUN_009c3de0`; **Inferred**) |
| **Review date** | `2026-07-29` (W25-I dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009c3de0_atexit_NetClassRep_rpcMsgGuaranteedOrdered.md` |
| **System** | networking / TNL ClassRep CRT |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf **atexit** destructor thunk for the static NetClassRepInstance of
`RPC_TNLConnection_rpcMsgGuaranteedOrdered`. Bakes `this` and tail-jumps to
shared ClassRep dtor. No pack/unpack/RPC logic.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009c3de0_FUN_009c3de0.md` |
| Annotated | `docs/reconstruction/raw/aa_009c3de0_FUN_009c3de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/atexit_NetClassRep_rpcMsgGuaranteedOrdered.cpp` |
| Function record | `docs/reconstruction/functions/aa_009c3de0_FUN_009c3de0.md` |
| Live decompile | `decompile_function` @ `0x009c3de0` |
| Machine | `read_memory` 16 B body; 48 B CRT init @ `0x009c0eb0` |
| Xrefs | DATA from `0x009c0ec5` only |
| Sibling dual | `aa_0059e1c0` Method1/getClassRep (ClassRep identity) |

---

## 3. Byte seal (`read_memory` @ `0x009c3de0`)

```
B9 40 4F B0 00     mov  ecx, 0x00b04f40
E9 86 E6 BD FF     jmp  FUN_005a2470          ; -> 0x005a2470
```

Full body hex (10 B):
```
b9404fb000e986e6bdff
```

| Claim | Confidence | Evidence |
|---|---|---|
| `this` imm = `0x00b04f40` | **High** | `b9 40 4f b0 00` |
| Tail jmp not call | **High** | `e9` opcode; no `c3` in body |
| Target `0x005a2470` | **High** | `0x009c3dea + 0xFFBDE686` |
| atexit registration | **High** | push imm at `0x009c0ec5` + call atexit |
| ClassRep identity | **High** | same storage as Method1; CRT name string; sibling seal |

### CRT init identity (context)

```
// 0x009c0eb0
push 0; push 2; push 1; push "RPC_TNLConnection_rpcMsgGuaranteedOrdered"
mov  ecx, 0x00b04f40
call FUN_005a2410          ; ClassRep ctor
push FUN_009c3de0
call _atexit
```

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Set ECX to static ClassRep | **Yes** (bytes; clean comment) |
| Transfer to FUN_005a2470 | **Yes** |
| No local work / no ret of own | **Yes** (jmp) |
| Decompiler call+return shape | Equivalent CF; prefer jmp fidelity |

---

## 5. Gaps

1. Compiler-generated atexit symbol string — open (Inferred).
2. Live process-exit observation — open / not required for thunk CF.
3. Full ClassRep dtor dual of `FUN_005a2470` — residual elsewhere (not owned).

**Verdict:** **accept**
