# Review B (skeptical / adversarial): `aa_005194f0` Gfx_BindMatDiffuseAmbientEmissive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005194f0` |
| **VA** | `0x005194f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9R-F) |
| **Counterpart** | `reviews/A_aa_005194f0_Gfx_BindMatDiffuseAmbientEmissive_Inferred.md` |
| **Tools** | decompile + read_memory + Capstone + xrefs (no Launcher, no disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a skill-bank cast helper (WQ-009 label) | Address sits in residual skill wave list | **Falsified as product domain** — only Mat* shader binds; no skill cast callees |
| 2 | Decompiler `FUN_009700f0("MatDiffuse", ptr)` is complete ABI | Looks like two-arg free function | **Falsified** — ECX = `entry+0x20`; two stack args; thiscall |
| 3 | `FUN_0051def0(0,0,0,0,g_flOne)` sets material to white | Literal 5-arg form | **Falsified as semantics** — ECX=colorVec, push size **0** → **clear** vector; float4 is unused fill for grow path |
| 4 | Assert stop is fatal process kill | `VOG_DEBUG_STOP` string | **Unproven** — only `FUN_007a4480(0,str)`; continues loop setup after |
| 5 | Color layout is RGB only | three names | **Incomplete** — each slot is **0x10** bytes (float4); alpha lane present in stride |
| 6 | `param_1` is the color bank | arg order | **Falsified** — first arg is shader host (`+0xc0`); second is colors |

---

## 2. Surviving contract

```
void Gfx_BindMatDiffuseAmbientEmissive_Inferred(void* shaderHost, void* colorVec /* begin@+4 end@+8 */);
  require count(shaderHost+0xc0) * 3 == count(colorVec float4s)
  for i in shaders:
    this = *(dword*)(host.begin + 4*i) + 0x20
    SetParam(this, "MatDiffuse",  color.begin + 0x30*i + 0x00)
    SetParam(this, "MatAmbient",  color.begin + 0x30*i + 0x10)
    SetParam(this, "MatEmissive", color.begin + 0x30*i + 0x20)
  colorVec.resize(0)
```

---

## 3. Open questions

1. What object class lives at `*(hostVec[i])`?
2. Does binder copy or reference the float4?
3. Caller when color count fails assert — production vs debug builds.
