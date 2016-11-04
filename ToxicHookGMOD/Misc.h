#pragma once

#include "SDK.h"
class CViewSetup
{
public:
	int			x, x_old;
	int			y, y_old;
	int			width, width_old;
	int			height, height_old;
	bool		m_bOrtho;
	float		m_OrthoLeft;
	float		m_OrthoTop;
	float		m_OrthoRight;
	float		m_OrthoBottom;
	bool		m_bCustomViewMatrix;
	matrix3x4_t	m_matCustomViewMatrix;
	char		pad_0x68[0x48];
	float		fov;
	float		fovViewmodel;
	Vector		origin;
	Vector		angles;
	float		zNear;
	float		zFar;
	float		zNearViewmodel;
	float		zFarViewmodel;
	float		m_flAspectRatio;
	float		m_flNearBlurDepth;
	float		m_flNearFocusDepth;
	float		m_flFarFocusDepth;
	float		m_flFarBlurDepth;
	float		m_flNearBlurRadius;
	float		m_flFarBlurRadius;
	int			m_nDoFQuality;
	int			m_nMotionBlurMode;
	float		m_flShutterTime;
	Vector		m_vShutterOpenPosition;
	Vector		m_shutterOpenAngles;
	Vector		m_vShutterClosePosition;
	Vector		m_shutterCloseAngles;
	float		m_flOffCenterTop;
	float		m_flOffCenterBottom;
	float		m_flOffCenterLeft;
	float		m_flOffCenterRight;
	int			m_EdgeBlur;
};

enum FontDrawType_t
{
	FONT_DRAW_DEFAULT = 0,
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,
	FONT_DRAW_TYPE_COUNT = 2,
};

typedef unsigned long HFont;

struct Vector2D
{
public:
	float x, y;

	Vector2D() {}
	Vector2D(float x_, float y_) { x = x_; y = y_; }
};

struct FontVertex_t
{
	Vector2D m_Position;
	Vector2D m_TexCoord;

	FontVertex_t() {}
	FontVertex_t(const Vector2D &pos, const Vector2D &coord = Vector2D(0, 0))
	{
		m_Position = pos;
		m_TexCoord = coord;
	}
	void Init(const Vector2D &pos, const Vector2D &coord = Vector2D(0, 0))
	{
		m_Position = pos;
		m_TexCoord = coord;
	}
};

typedef FontVertex_t Vertex_t;

struct surfacephysicsparams_t
{
	float			friction;
	float			elasticity;
	float			density;
	float			thickness;
	float			dampening;
};

struct surfaceaudioparams_t
{
	float			reflectivity;
	float			hardnessFactor;
	float			roughnessFactor;
	float			roughThreshold;
	float			hardThreshold;
	float			hardVelocityThreshold;
};

struct surfacesoundnames_t
{
	unsigned short	walkStepLeft;
	unsigned short	walkStepRight;
	unsigned short	runStepLeft;
	unsigned short	runStepRight;
	unsigned short	impactSoft;
	unsigned short	impactHard;
	unsigned short	scrapeSmooth;
	unsigned short	scrapeRough;
	unsigned short	bulletImpact;
	unsigned short	rolling;
	unsigned short	breakSound;
	unsigned short	strainSound;
};

struct surfacesoundhandles_t
{
	short	walkStepLeft;
	short	walkStepRight;
	short	runStepLeft;
	short	runStepRight;
	short	impactSoft;
	short	impactHard;
	short	scrapeSmooth;
	short	scrapeRough;
	short	bulletImpact;
	short	rolling;
	short	breakSound;
	short	strainSound;
};

struct surfacegameprops_t
{
public:
	float				maxSpeedFactor;
	float				jumpFactor;
	char				pad00[0x4];
	float				flPenetrationModifier;
	float				flDamageModifier;
	unsigned short		material;
	char				pad01[0x3];
};

struct surfacedata_t
{
	surfacephysicsparams_t	physics;
	surfaceaudioparams_t	audio;
	surfacesoundnames_t		sounds;
	surfacegameprops_t		game;
	surfacesoundhandles_t	soundhandles;
};

enum ClientFrameStage_t
{
	FRAME_UNDEFINED = -1,
	FRAME_START,
	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,
	FRAME_RENDER_START,
	FRAME_RENDER_END
};
struct player_info_t
{
	char __pad0[0x8];

	int xuidlow;
	int xuidhigh;

	char name[128];
	int userid;
	char guid[33];

	char __pad1[0x17B];
};