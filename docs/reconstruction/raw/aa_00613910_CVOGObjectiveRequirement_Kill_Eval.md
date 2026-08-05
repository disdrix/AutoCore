# Raw capture: CVOGObjectiveRequirement_Kill_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613910` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00613910` |
| **Canonical name** | `CVOGObjectiveRequirement_Kill_Eval` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall CVOGObjectiveRequirement_Kill_Eval(int param_1,undefined4 param_2,int param_3)

{
  if ((float)*(int *)(param_1 + 0x18) <= *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4))
  {
    return 1;
  }
  return 0;
}
```

---

## Re-verify append (2026-07-29 dual residual)

| Field | Value |
|---|---|
| Tool | Ghidra MCP `decompile_function` + `disassemble_function` |
| Body match | **Identical** to original raw capture |
| Integrity | Original raw body above preserved |

### Assembly (live)

```
00613910  MOVZX  EAX, byte ptr [ECX+0x8]
00613914  CVTSI2SS XMM0, dword ptr [ECX+0x18]
00613919  MOV    ECX, dword ptr [ESP+0x8]
0061391d  MOVSS  XMM1, dword ptr [ECX+EAX*4+0x4]
00613923  COMISS XMM1, XMM0
00613926  JC     0061392d
00613928  MOV    AL, 1
0061392a  RET    8
0061392d  XOR    AL, AL
0061392f  RET    8
```

### Notes sealed this pass

- Complete when progress ≥ required (COMISS; JC = less-than path).
- param_2 unread; state = `[ESP+8]`.
- DATA xref only `0x009e19ec` (vtable +0x8).
- Scratch: `tmp/a_00613910.md`.