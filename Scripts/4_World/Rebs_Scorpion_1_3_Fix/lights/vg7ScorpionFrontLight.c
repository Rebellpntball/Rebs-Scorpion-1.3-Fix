// Unique class name so we do NOT collide with the original vg7ScorpionFrontLight
// Retro 80s halogen / yellow headlight
class RebsScorpionFrontLight extends CarLightBase
{
	void RebsScorpionFrontLight()
	{
		// Segregated (single bulb) – classic warm halogen
		m_SegregatedBrightness = 5.5;
		m_SegregatedRadius = 58;
		m_SegregatedAngle = 105;
		m_SegregatedColorRGB = Vector(1.0, 0.82, 0.45);

		// Aggregated (both / brighter)
		m_AggregatedBrightness = 11;
		m_AggregatedRadius = 78;
		m_AggregatedAngle = 115;
		m_AggregatedColorRGB = Vector(1.0, 0.85, 0.50);

		FadeIn(0.25);
		SetFadeOutTime(0.2);

		SegregateLight();
	}
};
